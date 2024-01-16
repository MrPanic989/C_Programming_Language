#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AdDataLoader.h"
#include "AdConstants.h"
#include "AdTypes.h"


static VehicleType EGO_VEHICLE_DATA;
static VehicleType VEHICLE_DATA[NUM_VEHICLES][NUM_CYCLES];

void preload_ego_vehicle_data(const char datapath[128])
{
    char filepath[256] = {'\0'};
    strncpy(filepath, datapath, 128);   //copy absolute path to our data folder

    char filename[128] = "ego_data.txt";
    strncat(filepath, filename, 128);   //concatinate our ego vehicle file to the path

    FILE* fp = fopen(filepath, "r");
    if(fp == NULL)
    {
        return;
    }

    int line_size = 256;    //you take a bigger number
    char line[256] = {'\0'};

    fgets(line, line_size, fp);
    size_t lane_str_length = strlen("Lane: ");  //In our file the line looks like this: Lane: 2. And 2 is
                                                //the value that we want, so we have to do some pointer arithmetics
    int lane_idx = atoi(line + lane_str_length);    //We transform the value at the line[0 + line_str_length] into integer

    fgets(line, line_size, fp);
    size_t speed_str_length = strlen("Speed: ");
    float speed_mps = (float)atof(line + speed_str_length);

    EGO_VEHICLE_DATA.speed_mps = speed_mps;
    EGO_VEHICLE_DATA.distance_m = 0.0f;
    EGO_VEHICLE_DATA.lane = lane_idx;
    EGO_VEHICLE_DATA.vehicle_id = EGO_VEHICLE_ID;

    fclose(fp);
}

void preload_vehicle_data(const char datapath[128])
{
    for (int vehicle_idx = 0; vehicle_idx < NUM_VEHICLES; ++vehicle_idx)
    {
        char filepath[256] = {'\0'};
        strncpy(filepath, datapath, 128);
        char filename[128] = {'\0'};
        snprintf(filename, 128, "vehicle_%d_data.txt", vehicle_idx);    //snprintf() is used to store the specified string till a specified length in the specified format
        strncat(filepath, filename, 128);

        FILE *fp = fopen(filepath, "r");

        if (fp == NULL)
        {
            return;
        }

        int line_size = 256;
        char line[256] = {'\0'};

        fgets(line, line_size, fp);     //get the first string of the file, which is the lane
        size_t lane_str_len = strlen("Lane: ");
        int lane_idx = atoi(line + lane_str_len);

        fgets(line, line_size, fp);     //get the second string of the file, which is the distance
        size_t distance_str_len = strlen("Distance: ");
        float distance_m = (float)atof(line + distance_str_len);

        int idx = 0;
        while (fgets(line, line_size, fp) != NULL)  //from now on(line 3/string3) until the pointer doesnt point at NULL
        {
            char speed_str[128] = {'\0'};
            snprintf(speed_str, 128, "Speed %d: ", idx);
            size_t speed_str_len = strlen(speed_str);

            float speed_mps = (float)atof(line + speed_str_len);

            VEHICLE_DATA[vehicle_idx][idx].vehicle_id = vehicle_idx;
            VEHICLE_DATA[vehicle_idx][idx].speed_mps = speed_mps;
            VEHICLE_DATA[vehicle_idx][idx].distance_m = distance_m;
            VEHICLE_DATA[vehicle_idx][idx].lane = lane_idx;

            idx++;
        }

        fclose(fp);
    }

}

void init_ego_vehicle(VehicleType* ego_vehicle)
{
    ego_vehicle->vehicle_id = EGO_VEHICLE_DATA.vehicle_id;
    ego_vehicle->speed_mps = EGO_VEHICLE_DATA.speed_mps;
    ego_vehicle->distance_m = EGO_VEHICLE_DATA.distance_m;
    ego_vehicle->lane = EGO_VEHICLE_DATA.lane;
}

void init_vehicle(VehicleType* vehicle, const int32_t id, const uint32_t cycle)
{
    vehicle->vehicle_id = VEHICLE_DATA[id][cycle].vehicle_id;
    vehicle->speed_mps = VEHICLE_DATA[id][cycle].speed_mps;
    vehicle->distance_m = VEHICLE_DATA[id][cycle].distance_m;
    vehicle->lane = VEHICLE_DATA[id][cycle].lane;
}

void init_vehicles(NeighborVehiclesType* vehicles)
{
    //We initialize the vehicles stats ONLY for the first cycle, that means cycle 0!
    init_vehicle(&vehicles->vehicles_left_lane[0], 0, 0);
    init_vehicle(&vehicles->vehicles_left_lane[1], 1, 0);
    init_vehicle(&vehicles->vehicles_center_lane[0], 2, 0);
    init_vehicle(&vehicles->vehicles_center_lane[1], 3, 0);
    init_vehicle(&vehicles->vehicles_right_lane[0], 4, 0);
    init_vehicle(&vehicles->vehicles_right_lane[1], 5, 0);

}

void load_cycle(NeighborVehiclesType* vehicles, const uint32_t cycle)
{
    vehicles->vehicles_left_lane[0].speed_mps = VEHICLE_DATA[0][cycle].speed_mps;
    vehicles->vehicles_left_lane[1].speed_mps = VEHICLE_DATA[1][cycle].speed_mps;
    vehicles->vehicles_center_lane[0].speed_mps = VEHICLE_DATA[2][cycle].speed_mps;
    vehicles->vehicles_center_lane[1].speed_mps = VEHICLE_DATA[3][cycle].speed_mps;
    vehicles->vehicles_right_lane[0].speed_mps = VEHICLE_DATA[4][cycle].speed_mps;
    vehicles->vehicles_right_lane[1].speed_mps = VEHICLE_DATA[5][cycle].speed_mps;
}
