/*In this exercise, you have to implement the following time computations:
- clamp_value:
    -value as an in- and output parameter
    -min_value and max_valuie as the value range
    -the function will check whether:
        -The value is below min_value
            -If true: set to min_value
        -The value is above max_valuie
            -If true: set to max_valuie
    -E.g. -2.5 with min_value = -2.0 and max_valuie = 2.0 => clamp to -2.0
    -E.g. 2.5 with min_value = -2.0 and max_valuie = 2.0 => clamp to 2.0
- round_value:
    -value as an in- and output parameter
    -num_digits as input parameter that will define to how many digits to round
    (to be more precise we will cut off the digits)
    -E.g. 1.23456 with 1 digits => 1.20000
    -E.g. 1.23456 with 2 digits => 1.23000
    -E.g. 1.23456 with 3 digits => 1.23400
*/
#include <stdio.h>
#include <stdint.h>

void get_numbers(double* value, double* min_value, double* max_value, uint32_t* num_digits);
void clamp_value(double* value, double min_value, double max_value);
void round_value(double* value, uint32_t num_digits);

int main(void)
{
    double value = 0.0f;
    double min_value = 0.0f;
    double max_value = 0.0f;
    uint32_t num_digits = 0u;

    get_numbers(&value, &min_value, &max_value, &num_digits);

    clamp_value(&value, min_value, max_value);
    printf("The value now is: %.15lf\n", value);

    round_value(&value, num_digits);
    printf("The rounded value is: %.15lf\n", value);

    return 0;
}

void get_numbers(double* value, double* min_value, double* max_value, uint32_t* num_digits)
{
    printf("Please enter a value: ");
    scanf("%lf", value);

    while(1)
    {
        printf("Please enter now a range.First the lower and than the upper border: ");
        scanf("%lf%lf", min_value, max_value);

        if(*min_value < *max_value)
        {
            break;
        }
        else
        {
            printf("Your input is incorrect!\n");
            continue;
        }
    }

    while (1)
    {
        printf("Please enter now the number of decimal places you wish your value to round up to: ");
        scanf("%u", num_digits);

        if(*num_digits > 0u)
        {
            break;
        }
        else
        {
            printf("Your input is incorrect!\n");
            continue;
        }
    }
}

void clamp_value(double* value, double min_value, double max_value)
{
    if(*value < min_value)
    {
        *value = min_value;
    }
    else if(*value > max_value)
    {
        *value = max_value;
    }
}

void round_value(double* value, uint32_t num_digits)
{
    float decimal_places = 1.0f;

    for(uint32_t i = 0; i < num_digits; i++)
    {
        decimal_places *= 10.0f;
    }

    uint32_t temp_value = *value * decimal_places;

    *value = temp_value / decimal_places;
}
