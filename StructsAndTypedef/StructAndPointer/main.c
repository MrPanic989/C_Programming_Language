#include <stdio.h>

typedef struct
{
    char* name;
} s_user_data;

typedef struct
{
    int ID;
    s_user_data* user_data;
} s_account;

int main(void)
{
    s_user_data user_data_tim = {"Tim Wiese"};
    s_account account_tim = {
        .ID = 2351,
        &user_data_tim
    };

    s_account* account_tim_p = &account_tim;

    printf("User ID %d with name %s\n", account_tim.ID, account_tim.user_data->name);

    printf("User ID %d with name %s\n", account_tim_p->ID, account_tim_p->user_data->name);

    /*This example should make it clear when to use the '->' and when '.' operator.*/

    return 0;
}
