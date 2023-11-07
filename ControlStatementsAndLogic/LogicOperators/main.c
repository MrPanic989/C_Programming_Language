#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool has_money_on_the_bank = true;
    bool has_cash = false;
    bool has_debts = true;

    // and: && (ampersand)
    // or: || (pipes)
        //has_cash (is false) OR has_money_on_the_bank (is true)
    bool has_money = has_cash || has_money_on_the_bank;  //This logical statement (OR) is true even if just one statement is true.
    if (has_money)      //equivalent to if (has_money == true) or also if (has_cash || has_money_on_the_bank)
    {
        printf("We still have some money!\n");
    }
                    //has_debts (is true) AND has_money (in this case also true)
    bool has_debts_and_money = has_debts && has_money;  //This logical statement (AND) needs both statements to be true in order to be true itself.
    if (has_debts_and_money)
    {
        printf("We could theoretically pay off the debt!\n");
    }

    return 0;
}
