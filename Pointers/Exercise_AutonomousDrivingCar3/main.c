/*For this exercise, we will extend our AutonomousDrivingCar2 code.
We will add the option that the user can decide whether to change the lane
and to accelerate or decelerate the car.

For this implement the following function:
- get_user_input
Inside of this function you have to read whether the user wants to perform any actions.

In the AdTypes.h file create two enums:
- LongitudinalAction: for acceleration or deceleration action (or none)
- LateralAction: for lane change action (to left or right, or none)

After processing the user input, do a lane change and adapt the vehicle speed regarding the input.
- handle_lateral_user_input(lane_idx, lateral_action);
- handle_longitudinal_user_input(speed_mps, longitudinal_action);

The acceleration/deceleration is applied by increasing/reducing the current speed ( m/s ) by 5%.
For this we have the define LONGITUDINAL_DIFFERENCE_PERCENTAGE in AdConstants.h
The files utils.c and utils.h are also given. They are used for the clear_console() function.*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "utils.h"
#include "AdFunctions.h"

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
        scanf("%u", &selection);

        if(selection == 1)
        {
            break;
        }
        else if(selection == 2)
        {
            break;
        }
        else if(selection == 3)
        {
            break;
        }
        else
        {
            printf("Invalid input! Try again!\n");
            continue;
        }
    } while (true);

    while(true)
    {
        //clear_console();

        print_scene(current_speed, selection);
        get_user_input(&current_speed, &selection);

    }

    return 0;
}
