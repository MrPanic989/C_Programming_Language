#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** createFriendbook(unsigned int number_friends)
{
    char** friends = (char**)malloc(number_friends * sizeof(char*));

    if(friends == NULL)
    {
        return NULL;
    }

    for(unsigned int i = 0; i < number_friends; ++i)
    {
        friends[i] = (char*)malloc(20 * sizeof(char));
    }

    return friends;
}

char** freeFriendbook(char** friends, unsigned int number_friends)
{
    for(unsigned int i = 0; i < number_friends; ++i)
    {
        free(friends[i]);
    }

    free(friends);
    return NULL;
}

int main(void)
{
    unsigned int number_friends = 3;

    char** friends = createFriendbook(number_friends);  //Char pointer that points on a pointer which points on a character array.

    /*With strcpy() function, we are writting in a string.
    strcpy(friends[0], "Mahteus Ballack");
    strcpy(friends[1], "David Arnautovic");
    strcpy(friends[2], "Sami Kimmich");
    */

    /*A safer way is to use the strncpy() function, where a number of characters
    which you want to copy is additionally required.*/
    strncpy(friends[0], "Mahteus Ballack", 20);
    strncpy(friends[1], "David Arnautovic", 20);
    strncpy(friends[2], "Sami Kimmich", 20);

    //Concatination of a string to another, with maximum nr. of characters + null character.
    strncat(friends[2], " Sony", 6);

    for(unsigned int i = 0; i < number_friends; ++i)
    {
        printf("%s\n", friends[i]);
    }

    //With strlen() you get the length of the string without the null character.
    long unsigned int length0 = strlen(friends[0]);
    long unsigned int length1 = strlen(friends[1]);
    long unsigned int length2 = strlen(friends[2]);
    printf("%lu\n", length0);
    printf("%lu\n", length1);
    printf("%lu\n", length2);

    //strncmp() compares two strings for certain amount of characters.
    int compare0 = strncmp(friends[0], friends[1], 20);
    int compare1 = strncmp(friends[0], friends[2], 20);
    int compare2 = strncmp(friends[1], friends[2], 20);
    printf("%d\n", compare0);   //Zero if the strings are equal.
    printf("%d\n", compare1);   //Negative value if the first not identical charactar of the first string is smaller(ASCII table) than the character of the second string.
    printf("%d\n", compare2);   //Positive value if the charactar of the first string is greater than that of the second.

    //Find index of the first (strchr) and returns a pointer to it, respectively the last (strrchr) letter 'm' in the string.
    char* found_char0 = strchr(friends[2], 'm');
    char* found_char1 = strrchr(friends[2], 'm');
    if(found_char0 != NULL)
    {
        printf("%s\n", found_char0);
    }
    if(found_char1 != NULL)
    {
        printf("%s\n", found_char1);
    }

    //Finds a substring and returns a pointer to the first index of that letter.
    char* found_substring = strstr(friends[2], "ich");
    if(found_substring != NULL)
    {
        printf("%s\n", found_substring);
    }

    //Iterates the string until it finds the token you define.
    char* token = strtok(friends[2], " ");
    if(token != NULL)
    {
        printf("%s\n", token);
    }

    friends = freeFriendbook(friends, number_friends);

    return 0;
}
