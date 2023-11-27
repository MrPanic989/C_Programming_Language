#ifndef AD_TYPES_H
#define AD_TYPES_H

enum LaneAssociationType                //As the car can be on one line at the time, we created an enum instead
{                                       //to check with 'if-elseif' statements the condion all the time.
    LaneAssociationType_UNKNOWN_LANE,   //It is good practice to put the enum name infront of the enum variable.
    LaneAssociationType_LEFT_LANE,
    LaneAssociationType_CENTER_LANE,
    LaneAssociationType_RIGHT_LANE
};

#endif
