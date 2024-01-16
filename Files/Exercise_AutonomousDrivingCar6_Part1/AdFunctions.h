#ifndef AD_FUNCTIONS_H
#define AD_FUNCTIONS_H

#include <stdint.h>
#include <stdbool.h>

#include "AdTypes.h"

void print_scene(const VehicleType* ego_vehicle, const NeighborVehiclesType* vehicles);
/* As we want our car to be autonomous and not to have to input some values every time,
those three functions aren't needed anymore
void get_user_input(float* current_speed, uint32_t* selection);
void handle_lateral_user_input(uint32_t* selection, char lateral_action);
void handle_longitudinal_user_input(float* current_speed, char longitudinal_action);
*/

/*From now we are going to get all the stats from files, so we don't need these functions anymore
void init_ego_vehicle(VehicleType* ego_vehicle);
void init_vehicles(NeighborVehiclesType* vehicles);
void init_vehicle(VehicleType* vehicle,
                  const int32_t id,
                  const float speed_kph,
                  const float distance,
                  const LaneAssociationType lane);
*/

void print_vehicle(const VehicleType* vehicle); //Use const everytime where you are certain that
                                                //the paremeter should be ONLY input, that means it must not be
                                                //modified, just printed out, for example.
void print_neighbor_vehicles(const NeighborVehiclesType* vehicles);

float kph_to_mps(const float kph);

void compute_future_distance(VehicleType* vehicle,
                             const float ego_driven_distance,
                             const float seconds);

void compute_future_state(const VehicleType* ego_vehicle,
                          NeighborVehiclesType* vehicles,
                          const float seconds);

float mps_to_kph(const float mps);

void decrease_speed(VehicleType* ego_vehicle);

void longitudinal_control(const VehicleType* front_vehicle, VehicleType* ego_vehicle);

const VehicleType* get_vehicle_array(const LaneAssociationType ego_lane,
                                     const NeighborVehiclesType* vehicles);

LaneAssociationType get_lane_change_request(const VehicleType* ego_vehicle,
                                            const NeighborVehiclesType* vehicles);

bool lateral_control(const LaneAssociationType lane_change_request,
                     VehicleType* ego_vehicle);

#endif
