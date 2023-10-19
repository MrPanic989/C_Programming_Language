/*In this exercise, we will start with a project that will be extended over the next few times.
The scenario will be an autonomous driving car on a highway with three lanes.
For this exercise, we will read-in the following information from the console:
- The current speed (in meter per second $\frac{m}{s}$) of our vehicle
- The current lane (There are three lanes in total)

The lane will be represented by an enum LaneAssociationType with the following properties:
- Left Lane
- Center Lane
- Right Lane
- Unknown Lane (Error case)
*/
#include <stdio.h>

enum LaneAssociationType                //As the car can be on one line at the time, we created an enum instead
{                                       //to check with 'if-elseif' statements the condion all the time.
    LaneAssociationType_UNKNOWN_LANE,   //It is good practice to put the enum name infront of the enum variable.
    LaneAssociationType_RIGHT_LANE,
    LaneAssociationType_CENTER_LANE,
    LaneAssociationType_LEFT_LANE
};

int main()
{
    float current_speed = 0.0f;
    enum LaneAssociationType curren_lane = LaneAssociationType_UNKNOWN_LANE;
    unsigned int selection = 0u;

    printf("Create the properties of a vehicle.\n");
    printf("Speed in m/s: ");
    scanf("%f", &current_speed);
    printf("Lane (1=Right, 2=Center, 3=Left): ");
    scanf("%u", &selection);

    printf("\n\t L   C   R  \n");           //This is the main output of our highway.

    curren_lane = (enum LaneAssociationType)selection;
    switch (curren_lane)
    {
        case LaneAssociationType_LEFT_LANE:
        {
            printf("\t\b| V |   |   |\n");  //This is the output if the user chose the left lane of our highway.
            break;                          //The 'V' stand for our vehicle and the stripes represent the left, right
        }                                   //and center line.
        case LaneAssociationType_CENTER_LANE:
        {
            printf("\t\b|   | V |   |\n");
            break;
        }
        case LaneAssociationType_RIGHT_LANE:
        {
            printf("\t\b|   |   | V |\n");
            break;
        }
        default:
        {
            printf("Invalid input!\n");
            break;
        }
    }

    printf("\nSpeed: %f\n", current_speed);

    return 0;
}
