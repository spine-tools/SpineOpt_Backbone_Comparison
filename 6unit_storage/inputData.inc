
$GDXIN ./input/6unit_storage/inputData.gdx
$onempty

Set grid(*) ;
$LOADDC grid

Set node(*) ;
$LOADDC node

Set flow(*) ;
$LOADDC flow

Set unittype(*) ;
$LOADDC unittype

Set unit(*) ;
$LOADDC unit

Set unitUnittype(*,*) ;
$LOADDC unitUnittype

Set unit_fail(*) ;
$LOADDC unit_fail

Set unitUnitEffLevel(*,*,*) ;
$LOADDC unitUnitEffLevel

Set effLevelGroupUnit(*,*,*) ;
$LOADDC effLevelGroupUnit

Set group(*) ;
$LOADDC group

Parameter p_gn(*,*,*) ;
$LOADDC p_gn

Parameter p_gnn(*,*,*,*) ;
$LOADDC p_gnn

Parameter p_gnu_io(*,*,*,*,*) ;
$LOADDC p_gnu_io

Parameter p_gnuBoundaryProperties(*,*,*,*,*) ;
$LOADDC p_gnuBoundaryProperties

Parameter p_unit(*,*) ;
$LOADDC p_unit

Parameter p_unitConstraint(*,*) ;
$LOADDC p_unitConstraint

Parameter p_unitConstraintNode(*,*,*) ;
$LOADDC p_unitConstraintNode

Parameter ts_unit(*,*,*,*) ;
$LOADDC ts_unit

Set restype(*) ;
$LOADDC restype

Set restypeDirection(*,*) ;
$LOADDC restypeDirection

Set restypeReleasedForRealization(*) ;
$LOADDC restypeReleasedForRealization

Set restype_inertia(*) ;
$LOADDC restype_inertia

Parameter p_groupReserves(*,*,*) ;
$LOADDC p_groupReserves

Parameter p_groupReserves3D(*,*,*,*) ;
$LOADDC p_groupReserves3D

Parameter p_groupReserves4D(*,*,*,*,*) ;
$LOADDC p_groupReserves4D

Parameter p_gnuReserves(*,*,*,*,*) ;
$LOADDC p_gnuReserves

Parameter p_gnnReserves(*,*,*,*,*) ;
$LOADDC p_gnnReserves

Parameter p_gnuRes2Res(*,*,*,*,*,*) ;
$LOADDC p_gnuRes2Res

Parameter ts_reserveDemand(*,*,*,*,*) ;
$LOADDC ts_reserveDemand

Parameter p_gnBoundaryPropertiesForStates(*,*,*,*) ;
$LOADDC p_gnBoundaryPropertiesForStates

Parameter p_groupPolicyEmission(*,*,*) / /;

Parameter p_uStartupFuel(*,*,*) ;
$LOADDC p_uStartupFuel

Set flowUnit(*,*) ;
$LOADDC flowUnit

Set emission(*) ;
$LOADDC emission

Parameter p_nEmission(*,*) ;
$LOADDC p_nEmission

Parameter ts_cf(*,*,*,*) ;
$LOADDC ts_cf

Parameter ts_PriceChange(*,*) ;
$LOADDC ts_PriceChange

Parameter ts_influx(*,*,*,*) ;
$LOADDC ts_influx

Parameter ts_node(*,*,*,*,*) ;
$LOADDC ts_node

Parameter ts_gnn(*,*,*,*,*,*) ;
$LOADDC ts_gnn

Parameter p_s_discountFactor(*) ;
$LOADDC p_s_discountFactor

Set t_invest(*) ;
$LOADDC t_invest

Set utAvailabilityLimits(*,*,*) ;
$LOADDC utAvailabilityLimits

Parameter p_storageValue(*,*) ;
$LOADDC p_storageValue

Parameter ts_storageValue(*,*,*,*) ;
$LOADDC ts_storageValue

Set ugroup(*,*) ;
$LOADDC ugroup

Set gnugroup(*,*,*,*) ;
$LOADDC gnugroup

Set gn2ngroup(*,*,*,*) ;
$LOADDC gn2ngroup

Set gnGroup(*,*,*) ;
$LOADDC gnGroup

Set sGroup(*,*) ;
$LOADDC sGroup

Parameter p_groupPolicy(*,*) ;
$LOADDC p_groupPolicy

Parameter p_groupPolicyUnit(*,*,*) ;
$LOADDC p_groupPolicyUnit

Set gnss_bound(*,*,*,*) ;
$LOADDC gnss_bound

Set uss_bound(*,*,*) ;
$LOADDC uss_bound

Parameter ts_emissionPrice(*,*,*) ;
$LOADDC ts_emissionPrice

$offempty
