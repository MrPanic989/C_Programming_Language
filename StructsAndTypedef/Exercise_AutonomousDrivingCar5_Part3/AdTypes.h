#ifndef AD_TYPES_H
#define AD_TYPES_H

#include <stdint.h>

#include "AdConstants.h"

typedef enum                 //As the car can be on one line at the time, we created an enum instead
{                                       //to check with 'if-elseif' statements the condion all the time.
    LaneAssociationType_UNKNOWN_LANE,   //It is good practice to put the enum name infront of the enum variable.
    LaneAssociationType_LEFT_LANE,
    LaneAssociationType_CENTER_LANE,
    LaneAssociationType_RIGHT_LANE
} LaneAssociationType;

typedef enum
{
    LongitudinalAction_UNKNOWN_ACTION,
    LongitudinalAction_INCREASE_SPEED = 'w',
    LongitudinalAction_DECREASE_SPEED = 's'
} LongitudinalAction;

typedef enum
{
    LateralAction_NONE,
    LateralAction_LEFT = 'a',
    LateralAction_RIGHT = 'd'
} LateralAction;

typedef struct
{
    int32_t vehicle_id;
    LaneAssociationType lane;
    float speed_mps;
    float distance_m;
} VehicleType;

typedef struct
{
    VehicleType vehicles_left_lane[NUM_VEHICLES_ON_LANE];
    VehicleType vehicles_center_lane[NUM_VEHICLES_ON_LANE];
    VehicleType vehicles_right_lane[NUM_VEHICLES_ON_LANE];
} NeighborVehiclesType;



#endif
