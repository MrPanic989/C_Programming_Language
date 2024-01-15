#include <stdio.h>

struct Friend               //Struct is a way to group several related variables into one place
{                           //It is best practice that struct variables start with a capital letter
    char name[50];          //Each variable in the struct is known as a member of the struct
    char lastname[50];
    unsigned int year;
    unsigned int month;
    unsigned int day;
};
/*By the data types that you can "create" yourself, like structs or enums, there is a feature
that's called 'typedef' you can use, but don't have to.
typedef struct Friend

    char name[50];
    char lastname[50];
    unsigned int year;
    unsigned int month;
    unsigned int day;
}Friend_t;
Now every time you want to use the struct variable Friend, you don't have to type struct Friend peter or
struct Friend jan, just the alias Friend_t peter, Friend_t jan or as parameters in a function.
*/

/*call by value -> a copy of the struct is created and passed on. It would be much more efficient if
we could call up the function with call by reference, and we can.
void print_friend(struct Friend friend)
{
    printf("%s %s\n", friend.name, friend.lastname);
    printf("%u.%u.%u\n", friend.day, friend.month, friend.year);
}
*/
void print_friend(struct Friend* friend)     //call by reference -> a pointer to the struct is  passed on
{
    printf("%s %s\n", friend->name, friend->lastname);
    printf("%u.%u.%u\n", friend->day, friend->month, friend->year);
}

int main(void)
{                   //This is one possibility how one can initialize a struct variable
    struct Friend jan = {.name = "Jan", .lastname = "Schaffranek", .year = 1994u, .month = 2u, .day = 24u};
    struct Friend peter = {.name = "Peter", .lastname = "Lustig", .year = 1959u, .month = 8u, .day = 14u};
    struct Friend hans = {.name = "Hans", .lastname = "Mayer", .year = 1976u, .month = 12u, .day = 31u};

    struct Friend friend_book[] = {jan, peter, hans};   //Array of structs

    printf("%s\n", jan.name);       //With the point operator one can get to the data behind the struct
    printf("%s\n", jan.lastname);
    printf("%u\n", jan.year);

    printf("%s\n", friend_book[1].name);
    printf("%s\n", peter.lastname);
    printf("%u\n", peter.year);

    printf("%s\n", hans.name);
    printf("%s\n", hans.lastname);
    printf("%u\n", friend_book[2].year);

    print_friend(&jan);
    print_friend(&friend_book[1]);
    print_friend(&hans);

    return 0;
}
