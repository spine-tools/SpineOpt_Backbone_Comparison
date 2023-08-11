$ontext
This file is part of Backbone.

Backbone is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Backbone is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with Backbone.  If not, see <http://www.gnu.org/licenses/>.
$offtext

* =============================================================================
* --- Results Symbols Included in Output --------------------------------------
* =============================================================================

* --- Node Result Symbols -----------------------------------------------------

// r_state required for model structure !!!!!!!!!!!
r_state_gnft

// State variable slack results
r_stateSlack_gnft

// spill results
r_spill_gnft
r_spill_gn
r_spill_g
r_spill_gnShare

// required for model structure !!!!!!!!!!!
r_transfer_gnnft

// Energy transfer results
r_transferRightward_gnnft
r_transferLeftward_gnnft
r_transfer_gnn

// Marginal value of energy results
r_balance_marginalValue_gnft
r_balance_marginalValue_gnAverage
r_transferValue_gnnft
r_transferValue_gnn

// Other node related results
r_curtailments_gnft
r_curtailments_gn
r_diffusion_gnnft
r_diffusion_gnn


* --- Energy Generation/Consumption Result Symbols ----------------------------

// required for model structure !!!!!!!!!!!
r_gen_gnuft

// Energy generation results
r_gen_gnu
r_gen_gnft
r_gen_gn
r_gen_g
r_gen_gnuShare
r_gen_gnShare

// Approximate utilization rates
r_gen_utilizationRate_gnu

// Energy generation results based on input, unittype, or group
r_genByFuel_gnft
r_genByFuel_gn
r_genByFuel_g
r_genByFuel_fuel
r_genByFuel_gnShare
r_genByUnittype_gnft
r_genByUnittype_gn
r_genByGnuGroup_gn

// Energy consumption during startups 
r_gen_unitStartupConsumption_nu


* --- Unit Online, startup, and shutdown Result Symbols ----------------------------------------

// required for model structure !!!!!!!!!!!
r_online_uft
r_startup_uft
r_shutdown_uft

// other online, startup, and shutdown results
r_online_u
r_online_perUnit_u
r_startup_u
r_shutdown_u

* --- Investment Result Symbols -----------------------------------------------

// Invested unit count and capacity
r_invest_unitCount_u
r_invest_unitCapacity_gnu
r_invest_transferCapacity_gnn

* --- Emissions Results -----------------------------------------------

// emissions by activity type
r_emission_operationEmissions_gnuft
r_emission_operationEmissions_nu
r_emission_startupEmissions_nuft
r_emission_StartupEmissions_nu
r_emission_capacityEmissions_nu

// Emission sum results
r_emissionByNodeGroup
r_emission_nu
r_emission_n
r_emission_u
r_emission

* --- Reserve Result Symbols ----------------------------------------

// required for model structure !!!!!!!!!!!
r_reserve_gnuft
r_reserveTransferRightward_gnnft
r_reserveTransferLeftward_gnnft

// Unit level reserve results
r_reserve_gnu
r_reserve_gn
r_reserveByGroup_ft
r_reserveByGroup
r_reserve_gnuShare
r_reserve2Reserve_gnuft

// Other reserve results
r_reserve_marginalValue_ft
r_reserve_marginalValue_average
r_reserveDemand_largestInfeedUnit_ft
r_reserveTransferRightward_gnn
r_reserveTransferLeftward_gnn

* --- Dummy Result Symbols ----------------------------

// Results regarding solution feasibility
r_qGen_gnft
r_qGen_gn
r_qGen_g
r_qReserveDemand_ft
r_qReserveMissing_ft
r_qReserveDemand
r_qCapacity_ft


* --- Cost Result Symbols -----------------------------------------------------

// Total Objective Function
r_cost_objectiveFunction_t

// Unit Cost Components
r_cost_unitVOMCost_gnuft
r_cost_unitVOMCost_gnu
r_cost_unitFuelEmissionCost_gnuft
r_cost_unitFuelEmissionCost_u
r_cost_unitStartupCost_uft
r_cost_unitStartupCost_u
r_cost_unitShutdownCost_uft
r_cost_unitShutdownCost_u
r_cost_unitFOMCost_gnu
r_cost_unitInvestmentCost_gnu
r_cost_unitCapacityEmissionCost_nu

// Transfer Link Cost Components
r_cost_linkVOMCost_gnnft
r_cost_linkVOMCost_gnn
r_cost_linkInvestmentCost_gnn

// Nodal Cost Components
r_cost_stateSlackCost_gnt
r_cost_stateSlackCost_gn
r_cost_storageValueChange_gn

// Realized System Operating Costs
r_cost_realizedOperatingCost_gnft
r_cost_realizedOperatingCost_gn
r_cost_realizedOperatingCost_g
r_cost_realizedOperatingCost
r_cost_realizedOperatingCost_gnShare
r_cost_realizedNetOperatingCost_gn
r_cost_realizedNetOperatingCost_g
r_cost_realizedNetOperatingCost

// Realized System Costs
r_cost_realizedCost_gn
r_cost_realizedCost_g
r_cost_realizedCost
r_cost_realizedCost_gnShare
r_cost_realizedNetCost_gn
r_cost_realizedNetCost_g
r_cost_realizedNetCost

* --- Info and Diagnostic Result Symbols ----------------------------

// Info results
r_info_solveStatus
r_info_metadata
r_info_mSettings
r_info_t_realized

// Diagnostics
$iftheni.diag '%diag%' == yes
d_cop
d_eff
d_capacityFactor
d_nodeState
d_influx
$endif.diag


// OLD RESULTS, mostly here for inspiration
*r_onlineCap
*r_capacity_type
*r_storageValue