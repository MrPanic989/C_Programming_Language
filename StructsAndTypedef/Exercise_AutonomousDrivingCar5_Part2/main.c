/*For this exercise, we will extend our AutonomousDrivingCar5 code.
- Update the existing code:
    -Remove the user input of the ego vehicle values
    -Add const to every parameter and variable where it is appropriate
    -print_scene
        -This function now takes const VehicleType *ego_vehicle, const NeighborVehiclesType *vehicles
        -Inside the for-loop print out all vehicles at their correct position (distance and lane)
          L   C   R
100     |   |   |   |
80      | V |   |   |
60      |   | V |   |
40      |   |   | V |
20      |   |   |   |
0       |   | E |   |
-20     | V |   | V |
-40     |   | V |   |
-60     |   |   |   |
-80     |   |   |   |
-100    |   |   |   |

Start simulation?:
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

        print_scene(&ego_vehicle, &vehicles);

        sleep_console(500);
    }

    return 0;
}
