#include <stdio.h>

typedef enum FriendshipOrigin
{
    FriendshipOrigin_SCHOOL,
    FriendshipOrigin_FAMILY,
    FriendshipOrigin_OTHER,
} FriendshipOrigin_t;

typedef struct Date
{
    unsigned int year;
    unsigned int month;
    unsigned int day;
} Date_t;

typedef struct Friend
{
    char name[50];
    char prename[50];
    Date_t birthday;        //This is a normal Date_t struct, NOT A POINTER!! It's not a Date_t* birthday;
    FriendshipOrigin_t origin;
} Friend_t;

void print_date(Date_t* date)
{
    printf("%u.%u.%u\n", date->day, date->month, date->year);
}

void print_friend(Friend_t* friend)
{
    printf("%s %s\n", friend->prename, friend->name);
    print_date(&friend->birthday);  //print_date function expects an Date_t pointer
                    //If the variable left from operator is a pointer, then we use the '->'operator, otherwise the '.' operator
    printf("Year of birth: %u\n", friend->birthday.year);

    switch (friend->origin)
    {
        case FriendshipOrigin_SCHOOL:
        {
            printf("I know him from school\n");
            break;
        }
        case FriendshipOrigin_FAMILY:
        {
            printf("I know him from my family\n");
            break;
        }
        case FriendshipOrigin_OTHER:
        {
            printf("I know him from somewhere else\n ");
            break;
        }
    }
}

int main(void)
{
    Friend_t jan = {
        .name = "Schaffranek",
        .prename = "Jan",
        .birthday = {.year = 1994U, .month = 2U, .day = 24U},
        .origin = FriendshipOrigin_FAMILY,
    };
    Friend_t peter = {
        .name = "Lustig",
        .prename = "Peter",
        .birthday = {.year = 1959U, .month = 8U, .day = 13},
        .origin = FriendshipOrigin_OTHER,
    };
    Friend_t hans = {
        .name = "Meier",
        .prename = "Hans",
        .birthday = {.year = 1970U, .month = 12U, .day = 31},
        .origin = FriendshipOrigin_SCHOOL,
    };

    Friend_t friend_book[] = {jan, peter, hans};

    print_friend(&friend_book[0]);
    print_friend(&friend_book[1]);
    print_friend(&friend_book[2]);

    return 0;
}
