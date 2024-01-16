#include <stdio.h>
#include <string.h>

#include "Lib.h"

char PROJECT_DIR[] = "C:/Users/sinis/C_programming_language/";  //path of the project saved in a global variable

int main(void)
{   //Step 1: define where the file is!
    char input_filepath[100] = {'\0'};
    strncpy(input_filepath, PROJECT_DIR, 100);  //copy the PROJECT_DIR string into the input_filepath with total 100 characters
    strncat(input_filepath, "Files/Files_UnknownFileSizeReadWrite/InputData.txt", 60); //concatinates the relative path to the string. The InputData.txt MUST exist

    char output_filepath[100] = {'\0'};
    strncpy(output_filepath, PROJECT_DIR, 100);
    strncat(output_filepath, "Files/Files_UnknownFileSizeReadWrite/OutputData.txt", 60);

    //Step 2: open the file
    FILE* fp_in = fopen(input_filepath, "r");  //File object (allways a pointer!) that points and open the file
                                            //with certain permission, r = read in the file, w = write/print the data from the file
                                            // a = append (write to end)
    if(fp_in == NULL)  //If fp_in points at a file that doesn't exists for example
    {
        return 1;
    }

    //Step 3: read in the data where the file pointer is pointing into an array we have created
    char line[100] = {'\0'};
    int line_size = sizeof(line) / sizeof(line[0]);
    //fgets() get a string, line for line, from a file: where should the string be saved, size, from where
    while(fgets(line, line_size, fp_in) != NULL)    //fgets returns NULL when it get to the end
    {
        printf("As a string: %s", line);

        int value = atoi(line);     //if we have the case that we want to get values from strings,
                                    //we can use atoi() to 'cast' it to integer value, atof() for float,...
        printf("As an integer: %d\n\n", value);
    }

    //Step 4: close the file
    fclose(fp_in);


    FILE* fp_out = fopen(output_filepath, "w");     //if the file doesn't exist, the write permission will create one
                                                    //if the file however exist, the write permission will DESTROY CONTENT!!!
    if(fp_out == NULL)
    {
        return 1;
    }

    int data[5] = {1, 2, 3, 4, 5};

    for(unsigned int i = 0; i < 5; ++i)
    {
        char temp[50] = {'\0'};
        sprintf(temp, "Value: %d - LineEnd\n", data[i]);
        fputs(temp, fp_out);
    }

    fclose(fp_out);

    return 0;
}
