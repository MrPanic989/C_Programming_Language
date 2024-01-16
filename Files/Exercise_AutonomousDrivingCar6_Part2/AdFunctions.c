#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>   //For the fabs() function which casts values to absolute values (important for the vehicles behind us).

#include "AdTypes.h"
#include "AdFunctions.h"
#include "AdConstants.h"



void print_scene(const VehicleType* ego_vehicle, const NeighborVehiclesType* vehicles)
{
    LaneAssociationType current_lane = ego_vehicle->lane;

    printf("\n\t L   C   R  \n");           //This is the main output of our highway.

    //Small auxiliary variables that points to vehicles that have not yet been processed.
    size_t left_idx = 0;
    size_t center_idx = 0;
    size_t right_idx = 0;

    float offset_m = 10.0f;
    for(int32_t i = 100; i >= -100; i -= (int32_t)(offset_m))
    {
        //Current vehicle from the NeighborVehicles arrays (not processed yet)
        const VehicleType* left_vehicle = (left_idx > NUM_VEHICLES_ON_LANE) ? NULL : &vehicles->vehicles_left_lane[left_idx];
        const VehicleType* center_vehicle = (center_idx > NUM_VEHICLES_ON_LANE) ? NULL : &vehicles->vehicles_center_lane[center_idx];
        const VehicleType* right_vehicle = (right_idx > NUM_VEHICLES_ON_LANE) ? NULL : &vehicles->vehicles_right_lane[right_idx];

        char left_string[] = "   ";         //Those strings have to be initialized here in the loop
        char center_string[] = "   ";       //because they have to be reseted every iteration.
        char right_string[] = "   ";

        const float range_m = (float)i;
        //E.g. i = 60, distance_m = -18.5: (i >= distance) is true but (distance > (i - offset = 40)) is false
        //E.g. i = 0, distance_m = -18.5: first condition is true AND -18.5 > (0 - 20 = -20) is also true.
        //If the vehicle distance is in the ragne of the if() statement, then execute the strncpy
        if((left_vehicle != NULL) && (range_m >= left_vehicle->distance_m) && (left_vehicle->distance_m > (range_m - offset_m)))
        {
            strncpy(left_string, " V ", 4);
            left_idx++;
        }
        if((center_vehicle != NULL) && (range_m >= center_vehicle->distance_m) && (center_vehicle->distance_m > (range_m - offset_m)))
        {
            strncpy(center_string, " V ", 4);
            center_idx++;
        }
        if((right_vehicle != NULL) && (range_m >= right_vehicle->distance_m) && (right_vehicle->distance_m > (range_m - offset_m)))
        {
            strncpy(right_string, " V ", 4);
            right_idx++;
        }

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
                    strncpy(left_string, " E ", 4);     //If i == 0, the position of our vehicle at any time, copy
                    break;                              //the vehicle symbol V in the left lane, in this case. 4 characters including null character.
                }
                case LaneAssociationType_CENTER_LANE:
                {
                    strncpy(center_string, " E ", 4);
                    break;
                }
                case LaneAssociationType_RIGHT_LANE:
                {
                    strncpy(right_string, " E ", 4);
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


    printf("\nSpeed: %f\n\n", ego_vehicle->speed_mps);
}
/*
void handle_lateral_user_input(uint32_t* selection, char lateral_action)
{
    LateralAction next_lane = lateral_action;
    LaneAssociationType current_lane = *selection;

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
    LongitudinalAction speed_up_down = longitudinal_action;

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
*/

float kph_to_mps(const float kph)
{
    return kph / 3.6f;
}

/*
void init_ego_vehicle(VehicleType* ego_vehicle)
{
    ego_vehicle->vehicle_id = EGO_VEHICLE_ID;
    ego_vehicle->distance_m = 0.0f;

    ego_vehicle->speed_mps = kph_to_mps(135.0f);
    ego_vehicle->lane = LaneAssociationType_CENTER_LANE;

}
void init_vehicle(VehicleType* vehicle, const int32_t id, const float speed_kph, const float distance, const LaneAssociationType lane)
{
    vehicle->vehicle_id = id;
    vehicle->distance_m = distance;
    vehicle->speed_mps = kph_to_mps(speed_kph);
    vehicle->lane = lane;
}
void init_vehicles(NeighborVehiclesType* vehicles)
{
    init_vehicle(&vehicles->vehicles_left_lane[0], 0, 130.0f, 80.0f, LaneAssociationType_LEFT_LANE);
    init_vehicle(&vehicles->vehicles_left_lane[1], 1, 80.0f, -20.0f, LaneAssociationType_LEFT_LANE);
    init_vehicle(&vehicles->vehicles_center_lane[0], 2, 80.0f, 50.0f, LaneAssociationType_CENTER_LANE);
    init_vehicle(&vehicles->vehicles_center_lane[1], 3, 120.0f, -50.0f, LaneAssociationType_CENTER_LANE);
    init_vehicle(&vehicles->vehicles_right_lane[0], 4, 110.0f, 30.0f, LaneAssociationType_RIGHT_LANE);
    init_vehicle(&vehicles->vehicles_right_lane[1], 5, 90.0f, -30.0f, LaneAssociationType_RIGHT_LANE);
}
*/

void print_vehicle(const VehicleType* vehicle)
{
    printf("ID: %d\n", vehicle->vehicle_id);
    printf("Speed (m/s): %f\n", vehicle->speed_mps);
    printf("Distance (m): %f\n", vehicle->distance_m);
    printf("Lane: %d\n", vehicle->lane);
}

void print_neighbor_vehicles(const NeighborVehiclesType* vehicles)
{
    print_vehicle(&vehicles->vehicles_left_lane[0]);
    print_vehicle(&vehicles->vehicles_left_lane[1]);
    print_vehicle(&vehicles->vehicles_center_lane[0]);
    print_vehicle(&vehicles->vehicles_center_lane[1]);
    print_vehicle(&vehicles->vehicles_right_lane[0]);
    print_vehicle(&vehicles->vehicles_right_lane[1]);
}

void compute_future_distance(VehicleType* vehicle, const float ego_driven_distance, const float seconds)
{
    const float driven_distance = vehicle->speed_mps * seconds;
    vehicle->distance_m = vehicle->distance_m + (driven_distance - ego_driven_distance);
    //The distance of the current vehicle in comparison to ours! is:
    //E.g. our speed is 25 m/s and from the current vehicle is 22 m/s and it is 50m ahead of us,
    //that means that we have greater speed and that the distance to the current vehicle
    // will be smaller than it was a half second before. driven_distance = 22 m/s * 0.5s = 11 m.
    //distance_m = 50m + (11m - 12.5m) = 50m + (-1.5m) = 48.5m
}

void compute_future_state(const VehicleType* ego_vehicle, NeighborVehiclesType* vehicles, const float seconds)
{
    //What distance did we travel in the time. E.g. our speed is 25 m/s and we want to check our
    //distance in 0.5 seconds. 25 * 0.5 so we drove 12.5 meters in 0.5 seconds.
    const float ego_driven_distance = ego_vehicle->speed_mps * seconds;

    compute_future_distance(&vehicles->vehicles_left_lane[0], ego_driven_distance, seconds);
    compute_future_distance(&vehicles->vehicles_left_lane[1], ego_driven_distance, seconds);
    compute_future_distance(&vehicles->vehicles_center_lane[0], ego_driven_distance, seconds);
    compute_future_distance(&vehicles->vehicles_center_lane[1], ego_driven_distance, seconds);
    compute_future_distance(&vehicles->vehicles_right_lane[0], ego_driven_distance, seconds);
    compute_future_distance(&vehicles->vehicles_right_lane[1], ego_driven_distance, seconds);
}

float mps_to_kph(const float mps)
{
    return mps * 3.6f;
}

void decrease_speed(VehicleType* ego_vehicle)
{
    const float speed_decrease = ego_vehicle->speed_mps * LONGITUDINAL_DIFFERENCE_PERCENTAGE;

    if((ego_vehicle->speed_mps - speed_decrease) > 0.0f)
    {
        ego_vehicle->speed_mps = ego_vehicle->speed_mps - speed_decrease;
    }
}

void longitudinal_control(const VehicleType* front_vehicle, VehicleType* ego_vehicle)
{
    //The rule is: if our speed is 100km/h, our minimal distance to the vehicle infront of us
    //should be 50 meter.
    const float minimal_distance_m = mps_to_kph(ego_vehicle->speed_mps) / 2.0f;
    const float front_distance_m = front_vehicle->distance_m;

    if(front_distance_m < minimal_distance_m)
    {
        decrease_speed(ego_vehicle);
    }

}

const VehicleType* get_vehicle_array(const LaneAssociationType ego_lane, const NeighborVehiclesType* vehicles)
{
    switch(ego_lane)
    {
        case LaneAssociationType_LEFT_LANE:
        {
            return vehicles->vehicles_left_lane;
            break;
        }
        case LaneAssociationType_CENTER_LANE:
        {
            return vehicles->vehicles_center_lane;
            break;
        }
        case LaneAssociationType_RIGHT_LANE:
        {
            return vehicles->vehicles_right_lane;
            break;
        }
        case LaneAssociationType_UNKNOWN_LANE:
        default:
        {
            return NULL;
        }
    }
}

LaneAssociationType get_lane_change_request(const VehicleType* ego_vehicle, const NeighborVehiclesType* vehicles)
{
    const VehicleType* ego_lane_vehicles = get_vehicle_array(ego_vehicle->lane, vehicles);
    const VehicleType* rear_vehicle = &ego_lane_vehicles[1];

    const float minimal_distance_m = mps_to_kph(ego_vehicle->speed_mps) / 5.0f;
    const float rear_distance_m = (float)fabs(rear_vehicle->distance_m);

    if(rear_distance_m < minimal_distance_m)
    {
        switch (ego_vehicle->lane)
        {
            case LaneAssociationType_LEFT_LANE:
            {
                const VehicleType* centerlane_vehicles = get_vehicle_array(LaneAssociationType_CENTER_LANE, vehicles);

                const float front_center_distance_m = (float)fabs(centerlane_vehicles[0].distance_m);
                const float rear_center_distance_m = (float)fabs(centerlane_vehicles[1].distance_m);

                if((front_center_distance_m > minimal_distance_m) && (rear_center_distance_m > minimal_distance_m))
                {
                    return LaneAssociationType_CENTER_LANE;
                }

                break;
            }
            case LaneAssociationType_CENTER_LANE:
            {
                const VehicleType* rightlane_vehicles = get_vehicle_array(LaneAssociationType_RIGHT_LANE, vehicles);

                const float front_right_distance_m = (float)fabs(rightlane_vehicles[0].distance_m);
                const float rear_right_distance_m = (float)fabs(rightlane_vehicles[1].distance_m);

                if((front_right_distance_m > minimal_distance_m) && (rear_right_distance_m > minimal_distance_m))
                {
                    return LaneAssociationType_RIGHT_LANE;
                }

                const VehicleType* leftlane_vehicles = get_vehicle_array(LaneAssociationType_LEFT_LANE, vehicles);

                const float front_left_distance_m = (float)fabs(leftlane_vehicles[0].distance_m);
                const float rear_left_distance_m = (float)fabs(leftlane_vehicles[1].distance_m);

                if((front_left_distance_m > minimal_distance_m) && (rear_left_distance_m > minimal_distance_m))
                {
                    return LaneAssociationType_LEFT_LANE;
                }

                break;
            }
            case LaneAssociationType_RIGHT_LANE:
            {
                const VehicleType* centerlane_vehicles = get_vehicle_array(LaneAssociationType_CENTER_LANE, vehicles);

                const float front_center_distance_m = (float)fabs(centerlane_vehicles[0].distance_m);
                const float rear_center_distance_m = (float)fabs(centerlane_vehicles[1].distance_m);

                if((front_center_distance_m > minimal_distance_m) && (rear_center_distance_m > minimal_distance_m))
                {
                    return LaneAssociationType_CENTER_LANE;
                }
                break;
            }
            case LaneAssociationType_UNKNOWN_LANE:
            default:
            {
                break;
            }
        }
    }

    return ego_vehicle->lane; //If it is not necessary to change lane, that means the distanc to the vehicle in the back
                              //is large enough
}

bool lateral_control(const LaneAssociationType lane_change_request, VehicleType* ego_vehicle)
{
    if(lane_change_request == ego_vehicle->lane)
    {
        return false;
    }

    ego_vehicle->lane = lane_change_request;

    return true;
}
