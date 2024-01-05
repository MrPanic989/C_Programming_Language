/*Implement the following functions:
- char *to_upper_case_str(char *text);
    -Upper case all characters of the string
    -The upper case result is stored/overwritten in the input array

- char *to_lower_case_str(char *text);
    -Lower case all characters of the string
    -The lower case result is stored/overwritten in the input array

- char *char_search(char *text, char character);
    -Return the pointer to the position where the character is found in the string
    -If not found, return NULL

Note: Make sure that the input pointer is valid. test_cases() function is given.
*/
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "lib.h"

void test_cases();

int main(void)
{
    char input_text[128] = {'\0'};

    printf("Please enter any text: ");
    //scanf("%s", input_text);  With this line we are only able to save one consecutive word without
    //spaces between. That means that sentences are impossible to save

    /*n this example, fgets reads a line of text from stdin (standard input) and stores it in
    the input_text array. It also includes whitespaces in the input. The sizeof(input) argument
    ensures that fgets doesn't exceed the size of the array to prevent buffer overflow.*/
    fgets(input_text, sizeof(input_text), stdin);

    // Remove the newline character at the end, if present
    size_t len = strlen(input_text);
    if (len > 0 && input_text[len - 1] == '\n')
    {
        input_text[len - 1] = '\0';
    }

    printf("You entered: %s\n", input_text);

    printf("to_upper_case: %s\n", to_upper_case_str(input_text));
    printf("to_lower_case: %s\n", to_lower_case_str(input_text));
    printf("char_search: %s\n", char_search(input_text, 'a'));

    test_cases(); // This should not fail

    return 0;
}

void test_cases()
{
    char in_text[] = "JaNa";
    char text_up[] = "JANA";
    char text_low[] = "jana";

    char *to_upper = to_upper_case_str(in_text);
    assert(strncmp(to_upper, text_up, 4) == 0);
    char *to_lower = to_lower_case_str(in_text);
    assert(strncmp(to_lower, text_low, 4) == 0);
}
