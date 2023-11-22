#ifndef LIB_H
#define LIB_H

#include <stdbool.h>

bool is_numeric(const char value);
bool is_upper_case(const char value);
bool is_lower_case(const char value);
bool is_alpha(const char value);
bool is_alpha_numeric(const char value);
char to_upper_case(const char value);
char to_lower_case(const char value);

#endif
