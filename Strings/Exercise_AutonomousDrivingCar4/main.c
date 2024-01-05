/*For this exercise, we will extend our AutonomousDrivingCar3 code.
Update the print_scene function such that the following console output is printed
          L   C   R
100     |   |   |   |
80      |   |   |   |
60      |   |   |   |
40      |   |   |   |
20      |   |   |   |
0       |   | V |   |
-20     |   |   |   |
-40     |   |   |   |
-60     |   |   |   |
-80     |   |   |   |
-100    |   |   |   |

Speed: 23.000000

The vehicle will always be placed in row 0.
Only the lane (column) can be changed.
In future exercises, this plot will be used to display also other vehicles.
*/

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
