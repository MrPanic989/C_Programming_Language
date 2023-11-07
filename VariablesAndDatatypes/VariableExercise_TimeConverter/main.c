/*In this exercise, you have to use the datatype float for certain computations.

Implement the following time conversions:
- milliseconds to seconds
- seconds to minutes
- minutes to hours
- hours to days

Note:
- 1.000 Milliseconds = 1 Second
- 60 Seconds = 1 Minute
- 60 Minutes = 1 Hour
- 24 Hours = 1 Day
*/
#include <stdio.h>

float calculate_seconds(float i)
{
    float result;
    float milliseconds_to_seconds = 1.0F / 1000.0F;

    result = i * milliseconds_to_seconds;

    return result;
}

float calculate_minutes(float i)
{
    float result;
    float seconds_to_minutes = 1.0F / 60.0F;

    result = i * seconds_to_minutes;

    return result;
}

float calculate_hours(float i)
{
    float result;
    float minutes_to_hours = 1.0F / 60.0F;

    result = i * minutes_to_hours;

    return result;
}

float calculate_days(float i)
{
    float result;
    float hours_to_days = 1.0F / 24.0F;

    result = i * hours_to_days;

    return result;
}

int main(void)
{
    float milliseconds = 0.0F;
    float seconds = 0.0F;
    float minutes = 0.0F;
    float hours = 0.0F;
    float days = 0.0F;

    printf("Please enter the amount of milliseconds you want to convert: ");
    scanf("%f", &milliseconds);

    seconds = calculate_seconds(milliseconds);
    printf("\n%f milliseconds are %f seconds\n", milliseconds, seconds);

    minutes = calculate_minutes(seconds);
    printf("%f seconds are %f minutes\n", seconds, minutes);

    hours = calculate_hours(minutes);
    printf("%f minutes are %f hours\n", minutes, hours);

    days = calculate_days(hours);
    printf("%f hours are %f days\n", hours, days);

    return 0;
}
