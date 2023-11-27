#include <stdint.h>
#include <stdio.h>

#include "AdTypes.h"
#include "AdFunctions.h"



void print_scene(float current_speed, uint32_t selection)
{
    enum LaneAssociationType current_lane = selection;

    printf("\n\t L   C   R  \n");           //This is the main output of our highway.

    //curren_lane = (enum LaneAssociationType)selection;
    switch (current_lane)
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
}
