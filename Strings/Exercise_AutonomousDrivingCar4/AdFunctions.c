#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "AdTypes.h"
#include "AdFunctions.h"
#include "AdConstants.h"



void print_scene(float current_speed, uint32_t selection)
{
    enum LaneAssociationType current_lane = selection;

    printf("\n\t L   C   R  \n");           //This is the main output of our highway.

    float offset_m = 20.0f;

    for(int32_t i = 100; i >= -100; i -= (int32_t)(offset_m))
    {
        char left_string[] = "   ";         //Those strings have to be initialized here in the loop
        char center_string[] = "   ";       //because they have to be reseted every iteration.
        char right_string[] = "   ";

        if(i == 0)      //If i is 0 and we are in the correct row for vehicle, then we can modify our strings.
        {
            switch (current_lane)
            {   /*
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
                case LaneAssociationType_UNKNOWN_LANE:
                default:
                {
                    printf("Invalid input!\n");
                    break;
                }
                */
                 case LaneAssociationType_LEFT_LANE:
                {
                    strncpy(left_string, " V ", 4);     //If i == 0, the position of our vehicle at any time, copy
                    break;                              //the vehicle symbol V in the left lane, in this case. 4 characters including null character.
                }
                case LaneAssociationType_CENTER_LANE:
                {
                    strncpy(center_string, " V ", 4);
                    break;
                }
                case LaneAssociationType_RIGHT_LANE:
                {
                    strncpy(right_string, " V ", 4);
                    break;
                }
                case LaneAssociationType_UNKNOWN_LANE:
                default:
                {
                    break;
                }
            }
        }
            //In every iteration we have to print our highway, row for row.
        printf("%d\t|%s|%s|%s|\n", i, left_string, center_string, right_string);
    }


    printf("\nSpeed: %f\n", current_speed);
}

void handle_lateral_user_input(uint32_t* selection, char lateral_action)
{
    enum LateralAction next_lane = lateral_action;
    enum LaneAssociationType current_lane = *selection;

    switch (next_lane)
    {
        case LateralAction_LEFT:
        {
            switch (current_lane)
            {
                case LaneAssociationType_LEFT_LANE:
                {
                    return;
                    break;
                }
                case LaneAssociationType_CENTER_LANE:
                {
                    *selection = LaneAssociationType_LEFT_LANE;
                    break;
                }
                case LaneAssociationType_RIGHT_LANE:
                {
                    *selection = LaneAssociationType_CENTER_LANE;
                    break;
                }
                case LaneAssociationType_UNKNOWN_LANE:
                default:
                {
                    return;
                    break;
                }
            }
            break;
        }
        case LateralAction_RIGHT:
        {
            switch (current_lane)
            {
                case LaneAssociationType_LEFT_LANE:
                {
                    *selection = LaneAssociationType_CENTER_LANE;
                    break;
                }
                case LaneAssociationType_CENTER_LANE:
                {
                    *selection = LaneAssociationType_RIGHT_LANE;
                    break;
                }
                case LaneAssociationType_RIGHT_LANE:
                {
                    return;
                    break;
                }
                case LaneAssociationType_UNKNOWN_LANE:
                default:
                {
                    return;
                    break;
                }
            }
            break;
        }
        case LateralAction_NONE:
        default:
        {
            break;
        }
    }
}

void handle_longitudinal_user_input(float* current_speed, char longitudinal_action)
{
    enum LongitudinalAction speed_up_down = longitudinal_action;

    switch(speed_up_down)
    {
        case LongitudinalAction_DECREASE_SPEED:
        {
            float new_speed = (*current_speed) - ((*current_speed) * LONGITUDINAL_DIFFERENCE_PERCENTAGE);
            *current_speed = new_speed;
            break;
        }
        case LongitudinalAction_INCREASE_SPEED:
        {
            float new_speed = (*current_speed) + ((*current_speed) * LONGITUDINAL_DIFFERENCE_PERCENTAGE);
            *current_speed = new_speed;
            break;
        }
        case LongitudinalAction_UNKNOWN_ACTION:
        default:
        {
            break;
        }
    }
}


void get_user_input(float* current_speed, uint32_t* selection)
{
    char lateral_action = 'x';
    char longitudinal_action = 'x';

    printf("\nLongitudialAction (w=Increase, s=Decrease): ");
    scanf(" %c", &longitudinal_action);
    handle_longitudinal_user_input(current_speed, longitudinal_action);

    printf("\nLateralAction (a=Left, d=Right): ");
    scanf(" %c", &lateral_action);
    handle_lateral_user_input(selection, lateral_action);
}
