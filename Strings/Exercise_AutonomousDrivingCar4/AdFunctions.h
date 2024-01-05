#ifndef AD_FUNCTIONS_H
#define AD_FUNCTIONS_H

#include <stdint.h>

void print_scene(float current_speed, uint32_t selection);
void get_user_input(float* current_speed, uint32_t* selection);
void handle_lateral_user_input(uint32_t* selection, char lateral_action);
void handle_longitudinal_user_input(float* current_speed, char longitudinal_action);

#endif
