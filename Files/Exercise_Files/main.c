/*Tasks of the programming exercise:
- The result of the I/O task should be saved in a string of strings (text[][]).
- Read the text from the InputData.txt file iteratively:
    -Every single sentence of the text should be stored in a string of text
    -Assume that a maximum length of a sentence is 100 characters
    -Assume that there are a maximum of 10 sentences in the text
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char PROJECT_DIR[] = "C:/Users/sinis/C_programming_language/";

int main()
{
    char output_filepath[100] = {'\0'};
    strncpy(output_filepath, PROJECT_DIR, 100);
    strncat(output_filepath, "Files/Exercise_Files/InputData.txt", 60);

    FILE *fp = fopen(output_filepath, "r");

    if (NULL == fp)
    {
        return 1;
    }

    char text[10][100] = {'\0'};

    int idx = 0;
    int line_size = 100;
    char line[100] = {'\0'};

    while ((fgets(line, line_size, fp) != NULL) && (idx < 10))
    {
        strncpy(text[idx], line, 100);

        idx++;
    }

    for (unsigned int i = 0; i < 10; i++)
    {
        printf("%s\n", text[i]);
    }

    return 0;
}
