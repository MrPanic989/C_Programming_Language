#include <stdio.h>
#include <time.h>

void do_something()
{
    volatile double value = 0.0;    //volatile is used when you don't want the compiler to optimize your code

    for (unsigned int i = 0; i < 100000000; i++)
    {
        value += i;
    }
}

int main()
{
    clock_t clock_start = clock();      //clock() from the library time.h projects the CPU execution time
    do_something();
    clock_t clock_end = clock();
    clock_t duration1 = clock_end - clock_start;    //it doesn't show the execution time yet, but only how many cycles did it take

    time_t time_start = time(NULL);     //time() is used for real world time
    do_something();
    time_t time_end = time(NULL);
    double duration2 = (double)difftime(time_end, time_start);  //difftime() takes two time_t variables and compute the difference

    {
        double s = (double)duration1 / CLOCKS_PER_SEC;  //to convert to cycles to seconds, we have to divide it by CLOCKS_PER_SEC from our OS
        double ms = 1000.0 * s;
        double us = 1000.0 * ms;
        double ns = 1000.0 * us;

        printf("s: %lf\n", s);
        printf("ms: %lf\n", ms);
        printf("us: %lf\n", us);
        printf("ns: %lf\n", ns);
    }

    {
        double s = duration2;
        double ms = 1000.0 * s;
        double us = 1000.0 * ms;
        double ns = 1000.0 * us;

        printf("s: %lf\n", s);
        printf("ms: %lf\n", ms);
        printf("us: %lf\n", us);
        printf("ns: %lf\n", ns);
    }

    printf("Timestamp Start: %u\n", (unsigned int)time_start);  //projects the time, but in seconds since 1970
    printf("Timestamp End: %u\n", (unsigned int)time_end);

    printf("Time Format: %s\n", ctime(&time_end));  //ctime() to convert to hour:minute:seconds

    return 0;
}
