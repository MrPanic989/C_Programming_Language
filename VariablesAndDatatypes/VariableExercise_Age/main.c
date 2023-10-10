/* Tasks of the programming exercise:

- Read the user's age into the console (positive integer).
- Calculate how many days, hours, minutes and seconds he has already lived (to the number of whole years).
- Output the previously calculated values in the console.

Example:

This means, for example, if I enter 26 as age, the following output would be generated:
Please enter your age in years: 26
You are living since 9490 days
You are living since 227760 hours
You are living since 13665600 minutes
You are living since 819936000 seconds
*/

#include <stdio.h>

unsigned long long int age_in_days(unsigned long long int i)
{
    unsigned long long int result;
    unsigned long long int days_per_year = 365U;

    result = i * days_per_year;

    return result;
}

unsigned long long int age_in_hours(unsigned long long int i)
{
    unsigned long long int result;
    unsigned long long int hours_per_day = 24U;

    result = hours_per_day * age_in_days(i);

    return result;
}

unsigned long long int age_in_minutes(unsigned long long int i)
{
    unsigned long long int result;
    unsigned long long int minutes_per_hour = 60U;

    result = minutes_per_hour * age_in_hours(i);

    return result;
}

unsigned long long int age_in_seconds(unsigned long long int i)
{
    unsigned long long int result;
    unsigned long long int seconds_per_minute = 60U;

    result = seconds_per_minute * age_in_minutes(i);

    return result;
}

int main()
{
    /*unsigned int age = 0U;    Range 0 to 4,294,967,295. This could be a problem (overflow) if we
                                want to calculate some (most unlikely) ages in seconds, e.g. 140 years.
    Format specifier: %u
    */
    unsigned long long int age = 0U;    //Range 0 to 18,446,744,073,709,551,615

    printf("Please enter your age in years: ");
    scanf("%llu", &age);
    //printf("%llu\n", age);

    printf("\nYou are living since %llu days\n", age_in_days(age));
    printf("You are living since %llu hours\n", age_in_hours(age));
    printf("You are living since %llu minutes\n", age_in_minutes(age));
    printf("You are living since %llu seconds\n", age_in_seconds(age));

    return 0;
}
