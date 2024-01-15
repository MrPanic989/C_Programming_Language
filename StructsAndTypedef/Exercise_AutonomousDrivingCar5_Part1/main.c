/*For this exercise, we will extend our AutonomousDrivingCar4 code.
Create the following structs:
- VehicleType
    -vehicle id (int)
        Ego vehicle id is (-1), create a define for this
    -lane association
    -speed in m/s
    -distance to ego vehicle in meter

- NeighborVehiclesType
    -vehicles on left lane array with 2 entries in total
    -vehicles on center lane array with 2 entries in total
    -vehicles on right lane array with 2 entries in total
    -Create a define for the array length from above
    Note: The logic of these arrays is:
    -Index 0: Vehicle is in the front of the ego vehicle (distance > 0 at the start)
    -Index 1: Vehicle is in the back (rear) of the ego vehicle (distance < 0 at the start)

Implement the following functions:
- void init_ego_vehicle(VehicleType *ego_vehicle);
    -Set the speed, and lane of the ego vehicle
    -You can choose any speed € [20, 50]

- void init_vehicles(NeighborVehiclesType *vehicles);
    -Set the speed, and lane of all other vehicles (6 in total)
    -You can choose any speed € [20, 50]

- void print_vehicle(const VehicleType *vehicle);
    -print out all information of a vehicle

- void print_neighbor_vehicles(const NeighborVehiclesType *vehicles);
    -iterate over all other vehicles and print out their information
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
    return 0;
}
