#ifndef AD_FUNCTIONS_H
#define AD_FUNCTIONS_H

#include <stdint.h>

#include "AdTypes.h"

void print_scene(float current_speed, uint32_t selection);
void get_user_input(float* current_speed, uint32_t* selection);
void handle_lateral_user_input(uint32_t* selection, char lateral_action);
void handle_longitudinal_user_input(float* current_speed, char longitudinal_action);
void init_ego_vehicle(VehicleType *ego_vehicle);
void init_vehicles(NeighborVehiclesType *vehicles);
void print_vehicle(const VehicleType *vehicle);
void print_neighbor_vehicles(const NeighborVehiclesType *vehicles);
void init_vehicle(VehicleType* vehicle, int32_t id, float speed_kph, float distance, LaneAssociationType lane);
float kph_to_mps(float kph);

#endif
