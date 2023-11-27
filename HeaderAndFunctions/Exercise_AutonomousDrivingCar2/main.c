/*We will extens the self-driving car use-case from the AutonomousDrivingCar Part 1.
For this exercise, we will edit the following files:
- AdFunctions.h
- AdFunctions.c
- AdTypes.h

Content of AdFunctions.c/h:
- The print_scene function that prints out the console output from exercise Lanes1

Content of AdTypes.h:
- The Lane Enum

Note:
Don't forget to use include guards!
*/
#include <stdio.h>
#include <stdint.h>

#include "AdFunctions.h"

int main(void)
{
    float current_speed = 0.0f;

    uint32_t selection = 0u;

    printf("Create the properties of a vehicle.\n");
    printf("Speed in m/s: ");
    scanf("%f", &current_speed);
    printf("Lane (1=Left, 2=Center, 3=Right): ");
    scanf("%u", &selection);

    print_scene(current_speed, selection);

    return 0;
}
