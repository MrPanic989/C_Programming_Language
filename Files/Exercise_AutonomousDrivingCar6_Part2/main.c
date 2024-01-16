/*For this exercise, we will extend our AutonomousDrivingCar5 code.
Implement the following functions in the AdDataLoader.c/h:
- void init_ego_vehicle(VehicleType *ego_vehicle);
    -Load the ego vehicle data of the static global variable

- void init_vehicle(VehicleType *vehicle, const int32_t id, const uint32_t cycle);
    -Load the other vehicle data of the first cycle (index=0) of the static global variable

- void init_vehicles(NeighborVehiclesType *vehicles);
    -Load the other vehicle data of the first cycle (index=0) of the static global variable

- void load_cycle(NeighborVehiclesType *vehicles, const uint32_t cycle);
    -Load the other vehicle data of the current cycle of the static global variable
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "utils.h"
#include "AdFunctions.h"
#include "AdTypes.h"
#include "AdDataLoader.h"

const char datapath[128] = "C:/Users/sinis/C_programming_language/Files/Exercise_AutonomousDrivingCar6_Part1/data/";

int main()
{
    VehicleType ego_vehicle;
    NeighborVehiclesType vehicles;

    preload_ego_vehicle_data(datapath);
    preload_vehicle_data(datapath);

    init_ego_vehicle(&ego_vehicle);
    init_vehicles(&vehicles);

    print_vehicle(&ego_vehicle);
    print_neighbor_vehicles(&vehicles);

    printf("Start simulation?: ");
    char Input;
    scanf(" %c", &Input);

    for(uint32_t cycle = 0; cycle < NUM_CYCLES; ++cycle)
    {
        clear_console();
        load_cycle(&vehicles, cycle);

        print_scene(&ego_vehicle, &vehicles);
        compute_future_state(&ego_vehicle, &vehicles, 0.100f);

        const VehicleType* ego_lane_vehicles = get_vehicle_array(ego_vehicle.lane, &vehicles);
        longitudinal_control(&ego_lane_vehicles[0], &ego_vehicle);

        const LaneAssociationType lane_change_request = get_lane_change_request(&ego_vehicle, &vehicles);
        const bool lane_change_executed = lateral_control(lane_change_request, &ego_vehicle);

        if (lane_change_executed)
        {
            printf("Executed lane change!");
        }

        sleep_console(100);
    }

    return 0;
}
