/*For this exercise, we will extend our AutonomousDrivingCar5 code.
Implement the following functions:
- void compute_future_distance(VehicleType* vehicle, const float ego_driven_distance,
                               const float seconds);
    -Helper function for compute_future_state

- void compute_future_state(const VehicleType* ego_vehicle, NeighborVehiclesType* vehicles,
                            const float seconds);
    -Compute the position of all vehicles in n seconds

Hint:
The future distance of a vehicle is dependent on the ego vehicle speed and the
others vehicle speed. Since the ego vehicle is always at the distance (x) = 0,
hence the ego vehicle is the origin of the coordinate system.
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
    print_scene(&ego_vehicle, &vehicles);

    printf("Start simulation?: ");
    char Input;
    (void)scanf("%c", &Input);

    while (true)
    {
        clear_console();

        compute_future_state(&ego_vehicle, &vehicles, 0.500f);
        print_scene(&ego_vehicle, &vehicles);

        sleep_console(500);
    }

    return 0;
}
