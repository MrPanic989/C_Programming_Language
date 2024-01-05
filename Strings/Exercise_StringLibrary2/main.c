/*Implement the following functions:
- bool string_starts_with(char *string, char *substr);
    -Return true if the string starts with substr
    -E.g. string = "jan schaffranek", substr = "jan" => true
    -E.g. string = "jan schaffranek", substr = "an" => false

- bool string_ends_with(char *string, char *substr);
    -Return true if the string ends with substr
    -E.g. string = "jan schaffranek", substr = "anek" => true
    -E.g. string = "jan schaffranek", substr = "ane" => false

- char *string_find_first_not_of(char *string, char *substr);
    -Return the position of the string where the first character after the starting substr is
    -E.g. string = "jan schaffranek", substr = "jan s" => "chaffranek"
    -E.g. string = "jan schaffranek", substr = "ja" => "n schaffranek"

- char *string_n_copy(char *dest, char *src, size_t count);
    -Copy the content of src to dest with a maximal length of count

Note: Make sure that the input pointer is valid.
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "lib.h"

void test_cases();

int main()
{
    char text[128] = "Shot through the heart and you're to blame Darlin', you give love a bad name";
    char copy[128] = {'\0'};
    size_t length = strlen(text);

    printf("string_starts_with: %s\n", string_starts_with(text, "Shot") ? "true" : "false");
    printf("string_ends_with: %s\n", string_ends_with(text, "shot through") ? "true" : "false");

    printf("string_starts_with: %s\n", string_starts_with(text, "shot thr") ? "true" : "false");
    printf("string_ends_with: %s\n", string_ends_with(text, "name") ? "true" : "false");

    printf("string_find_first_not_of: %s\n", string_find_first_not_of(text, "Shot through the heart "));
    printf("string_find_first_not_of: %s\n", string_find_first_not_of(text, " an"));

    char* copied = string_n_copy(copy, text, length); //Get's as result pointer to the copy[].
    printf("New string: %s\n", copied);

    test_cases();

    return 0;
}

void test_cases()
{
    assert(string_ends_with("anna", "a") == true);
    assert(string_ends_with("anna", "na") == true);
    assert(string_ends_with("anna", "ann") == false);

    assert(string_starts_with("anna", "a") == true);
    assert(string_starts_with("anna", "na") == false);
    assert(string_starts_with("anna", "ann") == true);
}
