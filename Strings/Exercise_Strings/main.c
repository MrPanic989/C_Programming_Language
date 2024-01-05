/*Implement the "join" function
The join function accepts a delimiter (char*) and a list of strings list (char**).
In the function, all strings from the list are concatenated, but in contrast to normal concatenation,
the delimiter is packed in between the partial words
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h> //Because we don't know exactly how much memory we need for the final string,
                    //the size has to grow dynamically. That is why we have to be able to allocate
                    //memory on the heap.

char* join(char* delimiter, char** list)
{
    if(delimiter == NULL || list == NULL || list[0] == NULL)
    {                   //If there is no delimiter,or list doesn't point on anything, or the pointer points on nothing,
        return NULL;    //return NULL
    }

    size_t size = 0lu;
    while(list[size] != NULL)   //We want to find out how many elements there are in our list, or on how many pointers
    {                           //does the list pointer points to, how many char arrays are there.
        size++;
    }

    //Now we have to calculate the total length needed for the strings of the result string
    size_t all_string_length = 0lu;
    for(size_t i = 0lu; i < size; ++i)
    {
        all_string_length = all_string_length + strlen(list[i]);
    }
    //Now the total delimiter length    //size - 1 because if we have 3 elements, or strings, we will need 2 delimiters between them
    size_t delimiter_length = strlen(delimiter);
    size_t total_delimiter_length = (size - 1lu) * delimiter_length;

    //Finally we can now allocate memory needed for the whole string on the heap.
    size_t total_result_length = all_string_length + total_delimiter_length + 1lu;  //+ 1lu for the final null terminator
    char* result = (char*)malloc(total_result_length * sizeof(char));
    if(result == NULL)
    {
        return NULL;
    }

    strcpy(result, list[0]);        //Now the result contains the first string of the list
    for(size_t i = 1; i < size; i++)
    {
       strcat(result, delimiter);
       strcat(result, list[i]);
    }

    return result;
}

char* createString(char* result, char* delimiter, char** list)
{
    result = join(delimiter, list);
    if(result != NULL)
    {
        printf("List: %s\n", result);
        free(result);
        result = NULL;
    }

    return result;
}


int main(void)
{
    char* list1[] = {NULL};
    char* list2[] = {"Clara", NULL};
    char* list3[] = {"Clara", "Florian", NULL};
    char* list4[] = {"Clara", "Florian", "Jan", NULL};
    char* delimiter = " -> ";
    char* result = NULL;

    result = createString(result, delimiter, list1);
    result = createString(result, delimiter, list2);
    result = createString(result, delimiter, list3);
    result = createString(result, delimiter, list4);

    return 0;
}
