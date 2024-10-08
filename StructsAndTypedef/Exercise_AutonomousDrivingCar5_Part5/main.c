/*For this exercise, we will extend our AutonomousDrivingCar5 code.
Update the following functions:
- longitudinal_control
    -We don't pass in the front vehicle anymore
        -Get the front/rear vehicle internally get_vehicle_array
Implement the following functions:
- const VehicleType *get_vehicle_array(const LaneAssociationType ego_lane,
                                     const NeighborVehiclesType *vehicles)
    -Return the vehicle array for a certain lane

- LaneAssociationType get_lane_change_request(const VehicleType *ego_vehicle,
                                            const NeighborVehiclesType  *vehicles);
    -Send a lane change request if the vehicle would crash with the rear vehicle
        -If there is enough space on the right lane, send a request
        -Else If there is enough space on the left lane, send a request
        -Else, don't do anything
        -Check the size of the gap on the target lane

- bool lateral_control(const NeighborVehiclesType *vehicles,
                     const LaneAssociationType lane_change_request,
                     VehicleType *ego_vehicle);
    -If there is a request from get_lane_change_request do a lane change
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "utils.h"
#include "AdFunctions.h"
#include "AdTypes.h"

int main()
{
    VehicleType ego_vehicle;
    NeighborVehiclesType vehicles;

    init_ego_vehicle(&ego_vehicle);
    init_vehicles(&vehicles);

    print_vehicle(&ego_vehicle);
    print_neighbor_vehicles(&vehicles);

    printf("Start simulation?: ");
    char Input;
    scanf(" %c", &Input);

    while (true)
    {
        clear_console();

        print_scene(&ego_vehicle, &vehicles);
        compute_future_state(&ego_vehicle, &vehicles, 0.050f);

        const VehicleType* ego_lane_vehicles = get_vehicle_array(ego_vehicle.lane, &vehicles);
        longitudinal_control(&ego_lane_vehicles[0], &ego_vehicle);

        const LaneAssociationType lane_change_request =
            get_lane_change_request(&ego_vehicle, &vehicles);
        const bool lane_change_executed = lateral_control(lane_change_request, &ego_vehicle);

        if (lane_change_executed)
        {
            printf("Executed lane change!");
        }

        sleep_console(100);
    }

    return 0;
}
