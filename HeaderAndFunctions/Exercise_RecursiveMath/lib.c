#include <stdint.h>

#include "lib.h"

uint32_t recursive_sum(uint32_t lower_value, uint32_t upper_value)
{
    if(lower_value <= upper_value)
    {
        if(lower_value == upper_value)
        {
            return lower_value;
        }

        return lower_value + recursive_sum((lower_value + 1u), upper_value);
    }

    return 0u;

}


uint32_t recursive_product(uint32_t lower_value, uint32_t upper_value)
{
    if(lower_value <= upper_value)
    {
        if(lower_value == upper_value)
        {
            return lower_value;
        }
        else if((lower_value == 0u) || (upper_value == 0u))
        {
            return 0u;
        }
        else
        {
            return lower_value * recursive_product((lower_value + 1u), upper_value);
        }
    }

    return 0u;
}
