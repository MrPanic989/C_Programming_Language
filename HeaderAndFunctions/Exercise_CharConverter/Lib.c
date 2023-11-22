#include <stdbool.h>

#include "Lib.h"

bool is_numeric(const char value)            //This function checks if the character is a number
{
    if((value >= '0') && (value <= '9'))
    {
        return true;
    }

    return false;
}

bool is_upper_case(const char value)         //This function checks if the character is a capital letter
{
    if((value >= 'A') && (value <= 'Z'))
    {
        return true;
    }

    return false;
}

bool is_lower_case(const char value)         //This function checks if the character is a lowercase letter
{
    if((value >= 'a') && (value <= 'z'))
    {
        return true;
    }

    return false;
}

bool is_alpha(const char value)              //This function checks if the character is a letter at all.
{                                   //It calls up the two functions 'upper_case()' and 'lower_case()'
    if(is_upper_case(value) || is_lower_case(value))
    {
        return true;
    }

    return false;
}

bool is_alpha_numeric(const char value)
{
    if(is_numeric(value) || is_alpha(value))
    {
        return true;
    }

    return false;
}

char to_upper_case(const char value)
{
    if((is_alpha(value)) && (is_lower_case(value)))
    {
        return value - 32;
    }

    return value;
}

char to_lower_case(const char value)
{
    if((is_alpha(value)) && (is_upper_case(value)))
    {
        return value + 32;
    }

    return value;
}
