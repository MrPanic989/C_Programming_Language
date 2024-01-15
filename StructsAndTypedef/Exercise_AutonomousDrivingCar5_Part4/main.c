/*For this exercise, we will extend our AutonomousDrivingCar5 code.
Update the following functions:
- print_scene:
    -Update the distance slices to 10m instead of 20m
- Implement the following functions:
    -float mps_to_kph(const float mps);
        -Convert m/s to km/s value
    -void decrease_speed(VehicleType *ego_vehicle);
        -Decrease the speed by the LONGITUDINAL_DIFFERENCE_PERCENTAGE
    -void longitudinal_control(const VehicleType *front_vehicle, VehicleType *ego_vehicle);
        -If there is a vehicle in front of the ego vehicle and the distance is below
         half speed (kph, "halbe tacho"), the vehicle needs to decrease_speed
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "utils.h"
#include "AdFunctions.h"
#include "AdTypes.h"
/*
int main(void)
{
    float current_speed = 0.0f;

    uint32_t selection = 0u;

    printf("Create the properties of a vehicle.\n");
    printf("Speed in m/s: ");
    scanf("%f", &current_speed);
    do
    {
        printf("Lane (1=Left, 2=Center, 3=Right): ");
        scanf(" %u", &selection);

        if(selection < 1 || selection > 3)
        {
            printf("Invalid input. Please enter 1, 2 or 3.\n");
        }
    } while (selection != 1 && selection != 2 && selection != 3);

    while(true)
    {
        clear_console();

        print_scene(current_speed, selection);
        get_user_input(&current_speed, &selection);

    }

    return 0;
}
*/
int main()
{
    VehicleType ego_vehicle;
    NeighborVehiclesType vehicles;

    init_ego_vehicle(&ego_vehicle);
    init_vehicles(&vehicles);

    print_vehicle(&ego_vehicle);
    print_neighbor_vehicles(&vehicles);

    /*
    printf("Create the properties of a vehicle.\n");

    float speed_mps;
    printf("Speed in m/s: ");
    scanf("%f", &speed_mps);

    uint32_t lane_idx;
    printf("Lane (1=Right, 2=Center, 3=Left): ");
    scanf("%u", &lane_idx);

    while (true)
    {
        clear_console();

        print_scene(speed_mps, lane_idx);
        get_user_input(&speed_mps, &lane_idx);
    }
    */

    printf("Start simulation?: ");
    char Input;
    (void)scanf("%c", &Input);

    while (true)
    {
        clear_console();

        print_scene(&ego_vehicle, &vehicles);
        compute_future_state(&ego_vehicle, &vehicles, 0.100f);
        longitudinal_control(&vehicles.vehicles_center_lane[0], &ego_vehicle);

        sleep_console(100);
    }

    return 0;
}
