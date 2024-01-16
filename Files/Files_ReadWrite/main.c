#include <stdio.h>
#include <string.h>

#include "Lib.h"

char PROJECT_DIR[] = "C:/Users/sinis/C_programming_language/";  //path of the project saved in a global variable

int main(void)
{   //Step 1: define where the file is!
    char input_filepath[100] = {'\0'};
    strncpy(input_filepath, PROJECT_DIR, 100);  //copy the PROJECT_DIR string into the input_filepath with total 100 characters
    strncat(input_filepath, "Files/Files_ReadWrite/InputData.txt", 50); //concatinates the relative path to the string. The InputData.txt MUST exist

    char output_filepath[100] = {'\0'};
    strncpy(output_filepath, PROJECT_DIR, 100);
    strncat(output_filepath, "Files/Files_ReadWrite/OutputData.txt", 50);

    //Step 2: open the file
    FILE* fp_in = fopen(input_filepath, "r");  //File object (allways a pointer!) that points and open the file
                                            //with certain permission, r = read in the file, w = write/print the data from the file
                                            // a = append (write to end)
    if(fp_in == NULL)  //If fp_in points at a file that doesn't exists for example
    {
        return 1;
    }

    //Step 3: read in the data where the file pointer is pointing into an array we have created
    Vector v1 = {.data = createArray(5, 0), .length = 5};

    for(unsigned int i = 0; i < v1.length; ++i)
    {
        fscanf(fp_in, "%d", &v1.data[i]);  //fscanf() is the function which is used to read in a file
    }       //file, data type, where should data be saved

    //Step 4: close the file
    fclose(fp_in); //when we don't need the file anymore, we should close it fith fclose()


    //Step 5: now you can manipulate the data as you like.
    for(unsigned int i = 0; i < v1.length; ++i)
    {
        v1.data[i] -= 1;
        printf("%d\n", v1.data[i]);
    }

    FILE* fp_out = fopen(output_filepath, "w");     //if the file doesn't exist, the write permission will create one
                                                    //if the file however exist, the write permission will DESTROY CONTENT!!!
    if(fp_out == NULL)
    {
        return 1;
    }

    for(unsigned int i = 0; i < v1.length; ++i)
    {
        fprintf(fp_out, "%d\n", v1.data[i]);    //fprintf() write the data into a file
    }

    fclose(fp_out);

    FILE* fp_out_append = fopen(output_filepath, "a");   //does not destroy file date but appends data to its end

    if(fp_out_append == NULL)
    {
        return 1;
    }

    for(unsigned int i = 0; i < v1.length; ++i)
    {
        fprintf(fp_out_append, "%d\n", v1.data[i]);    //fprintf() write the data into a file
    }

    fclose(fp_out_append);

    freeArray(v1.data); //don't forget to free the reserved memory on the heap

    return 0;
}
