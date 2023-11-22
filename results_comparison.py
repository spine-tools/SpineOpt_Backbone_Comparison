import sys
import spinedb_api as api
import numpy as np
np.seterr(all='raise')
from tabulate import tabulate

#fixing a threshold under which a value is considered to be 0, due to numerical computing errors
EPSILON = 1e-9

url_backbone = sys.argv[1]
url_spineopt = sys.argv[2]

db_bb = api.DatabaseMapping(url_backbone)
db_so = api.DatabaseMapping(url_spineopt)

try:
    del db_out
except NameError:
    pass
except Exception as Error:
    print(f"Unexpected {Error = }, {type(Error) = }")

try:
    url_out = sys.argv[3]
    db_out = api.DatabaseMapping(url_out)
except IndexError:
    pass
except Exception as Error:
    print(f"Unexpected {Error = }, {type(Error) = }")

bb_data = api.export_data(db_bb)
so_data = api.export_data(db_so)

try:
    new_parameter_values = []
    results = []
    alternative_name = bb_data['alternatives'][0][0] + "_" + so_data['alternatives'][0][0]

    for value_so in so_data['relationship_parameter_values']:
        for value_bb in bb_data['relationship_parameter_values']:
            for parameter_name in ["total_costs", "unit_flow", "units_on", "node_state"]:
                object_name_so = []

                #deleting the directions from spineopt data aswe don't know it in BB one
                for element in value_so[1]:
                    if element!='from_node' and element!='to_node':
                        object_name_so.append(element)
                
                #matching spineopt data and backcone data based on the parameter name and object names
                if value_bb[2]==parameter_name and value_so[2]==parameter_name and tuple(object_name_so) == value_bb[1]:

                    #formatting backbone data: deleting 't000000' value when it exists, filling the holes in the data with zeros
                    bb_indexes = []
                    for i in range(len(value_bb[3].indexes)):
                        bb_indexes.append(int(value_bb[3].indexes[i].replace('t','')))
                    i_f = len(value_so[3].values)
                    bin_list = []
                    ind_assoc = {}
                    for i in range(i_f+1):
                        if i in bb_indexes:
                            bin_list.append(True)
                            ind_assoc[i] = bb_indexes.index(i)
                        else:
                            bin_list.append(False)
                    bb_values_dict = {}
                    for i in range(i_f+1):
                        if bin_list[i]:
                            bb_values_dict[i] = value_bb[3].values[ind_assoc[i]]
                        else:
                            bb_values_dict[i] = 0.
                    bb_values = []
                    begin_ind = 1 if 't' in value_bb[3].indexes[0] else 0
                    for i in range(begin_ind,len(bb_values_dict.keys())-(1-begin_ind)):
                        bb_values.append(bb_values_dict[i])
                    bb_values = np.array(bb_values)
                    
                    so_values = np.array(value_so[3].values)

                    #backbone total costs are in M_euros, whereas SpinOpt ones are in euros
                    if parameter_name == "total_costs":
                        bb_values = 1000000.0*bb_values

                    #computing a difference value (we could use whatever indicator of the deviation)
                    try:
                        final_values = (np.abs(bb_values)-np.abs(so_values))
						##/(np.abs(bb_values)+np.abs(so_values))*2*100
                    except FloatingPointError:
                        final_values = np.abs(np.abs(bb_values)-np.abs(so_values))
                        pass
                    except Exception as Error:
                        print(f"Unexpected {Error = }, {type(Error) = }")
                        continue

                    #finally formatting the values and adding them to the output database
                    final_values = list(final_values)
                    final_values_new_format = {
                        "type": "array",
                        "data": final_values
                    }
                    new_parameter_values.append((value_so[0],value_so[1],value_so[2],final_values_new_format,alternative_name))

                    #and letting know the tests results in the console
                    try:
                        assert np.max(final_values)<=EPSILON*100
                        results.append([str(value_so[1]),str(value_so[2]),'results EQUAL']) 
                        ##str(value_so[1])+" | "+str(value_so[2])+": "+"results EGAL.".rjust())
                    except AssertionError:
                        results.append([str(value_so[1]),str(value_so[2]),'results NOT equal'])
                        continue
                    except Exception as Error:
                        print(f"Unexpected {Error = }, {type(Error) = }")
                        continue

    print(tabulate(results))

    input_data = api.export_data(db_so)
    input_data["alternatives"]=[alternative_name]
    input_data["relationship_parameter_values"]=new_parameter_values

    try:
        api.import_data(db_out,**input_data)
        db_out.commit_session("success")
    except NameError:
        pass
    except Exception as Error:
        print(f"Unexpected {Error = }, {type(Error) = }")
        pass
    
except Exception as Error:
    print(f"Unexpected {Error = }, {type(Error) = }")
    pass

db_bb.connection.close()
db_so.connection.close()

try:
    db_out.connection.close()
except NameError:
    pass
except Exception as Error:
    print(f"Unexpected {Error = }, {type(Error) = }")
    pass