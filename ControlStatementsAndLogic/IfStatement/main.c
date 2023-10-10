#include <stdio.h>
#include <stdbool.h>

int main()
{               //unsigned int because ages cannot be negative
    unsigned int age_sarah = 0U;
    unsigned int age_jan = 0U;
    unsigned int age_marc = 0U;

    printf("Who is the youngest person in the room? Sarah, Jan or maybe Marc?\n");

    printf("How old is Sarah: ");
    scanf("%u", &age_sarah);

    printf("How old is Jan: ");
    scanf("%u", &age_jan);

    printf("How old is Marc: ");
    scanf("%u", &age_marc);
                //Now we define our booleans and compare the statements to find out who is the youngest
    bool is_jan_the_youngest = (age_jan < age_marc) && (age_jan < age_sarah);   //If Jan is younger than Marc AND younger than Sarah, he is then the youngest among them.
    bool is_sarah_the_youngest = (age_sarah < age_jan) && (age_sarah < age_marc);
    bool is_marc_the_youngest = (age_marc < age_jan) && (age_marc < age_sarah);
    bool are_all_the_same_age = (age_jan == age_marc) && (age_marc == age_sarah);//If Jan and Marc are of the same age AND Marc and Sarah also, then this means that all three have the same age.

    if (is_jan_the_youngest)
    {
        printf("\nJan is the youngest person in the room!\n");
    }
    else if (is_marc_the_youngest)
    {
        printf("Marc is the youngest person in the room!\n");
    }
    else if (is_sarah_the_youngest)
    {
        printf("Sarah is the youngest person in the room!\n");
    }
    else if (are_all_the_same_age)
    {
        printf("All have the same age!\n");
    }
    else  //If nothing above fits our case, then it means that two of theme have the same age and one is older.
    {
        printf("Two of the three persons have the same age. Let's find out who!\n");
        if (age_jan == age_marc)
        {
            printf("Jan and Marc have the same age. This means that Sarah is the oldest one of them!\n");
        }
        else if (age_jan == age_sarah)
        {
            printf("Jan and Sarah have the same age. This means that Marc is the oldest one of them!\n");
        }
        else
        {
            printf("Sarah and Marc have the same age. This means that Jan is the oldest one of them!\n");
        }
    }

    return 0;
}
