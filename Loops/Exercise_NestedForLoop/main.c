/*Implement a nested for loop to generate the following console output:
<       ^       ^       ^       ^       >
<     (1,1)   (1,2)   (1,3)   (1,4)     >
<     (2,1)   (2,2)   (2,3)   (2,4)     >
<     (3,1)   (3,2)   (3,3)   (3,4)     >
<     (4,1)   (4,2)   (4,3)   (4,4)     >
<       v       v       v       v       >

- Left arrow (< - smaller symbol)
- Right arrow (> - larger symbol)
- Arrow Up (^ - circumflex)
- Arrow Down (v - the letter)
*/
#include <stdio.h>
/*Version 1: This is if the solution should be more static, that means if it is only for the task abowe. (6x6 matrix)
int main()
{
    printf("<\t  ^\t  ^\t  ^\t  ^\t>\n");   //

    for(int i = 1; i <= 4; i++)         //Because it is a 2dim. matrix, we should use a nested 'for' loops.
    {
        printf("<\t");
        for(int j = 1; j <= 4; j++)
        {
            printf("(%d,%d)\t", i, j);
            if(j == 4)
            {
                printf(">\n");
            }
        }
    }

    printf("<\t  v\t  v\t  v\t  v\t>\n");

    return 0;
}
*/
//Version 2: For more general purpose, this is the version one should implement.
int main()
{
    int input = 0;

    printf("Please enter the number of rows/columns: ");
    scanf("%d", &input);

    for (int i = 0; i < input; i++)
    {
        for (int j = 0; j < input; j++)
        {                               //It can only be one state per iteration.
            if (j == 0)                 //1.Step: i = 0, j = 0 and we enter the loop. if (j == 0) is true, so we print "<\t" and increase j++;
            {                           //2.Step: i = 0, j = 1 and we enter the loop. The first statement is false, the second also
                printf("<\t");          //but the third (i == 0) is true, so we print now "  ^\t", and increase j++;
            }                           //3.Step: i = 0, j = 2. The output is the same as in step 2. j++; and so on,
            else if (j == (input - 1))  //until the condition of the second 'for' loop isn't valid anymore and than we increase the variable i++ of the first loop.
            {                           //Now is i = 1, j = 0 and so is the statement (j == 0) true and we print "<\t" out and increase again j++;
                printf(">\t");          //i = 1, j = 1 and now is the first time we can actually print out our first pair of the matrix. (1,1)
            }                           //i = 1, J = 2 ......
            else if (i == 0)
            {
                printf("  ^\t");
            }
            else if (i == (input - 1))
            {
                printf("  v\t");
            }
            else
            {
                printf("(%d,%d)\t", i, j);
            }
        }

        printf("\n");   //Each time we exit the second loop, we have to print out the new line.
    }

    return 0;
}
