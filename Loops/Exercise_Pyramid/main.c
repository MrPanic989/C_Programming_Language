#include <stdio.h>

void reverse(int height, char character)    //void function means that we do not have a returning value. It is used only for output.
{
    for(int i = height; i > 0; i--)     //Again we use the first 'for' loop for the height of the pyramid, but now
    {                                   //we start from the highest point.
        for(int j = 0; j < i; j++)
        {
            printf("%c ", character);
        }
        printf("\n");
    }
}

int main()
{
    char character = 'x';
    int height = 0;

    printf("Please enter the character of wich you want to build a pyramid: ");
    scanf("%c", &character);
    printf("How tall should the pyramid be: ");         //We read in the max height of the pyramid and also the
    scanf("%d", &height);                               //'building blocks' of the pyramid.
                  //This 'i' decides how much character in that row are going to be.
    for(int i = 1; i <= height; i++)        //The first 'for' loop is for the rows, in our case height, of our pyramid.
    {
        for(int j = 0; j < i; j++)      //The second 'for' loop is for the building blocks per row.
        {                               //First iterationg: i = 1 and j = 0, so j < i and we add the first block and increase j by 1 and so on.
            printf("%c ", character);
        }
        printf("\n");   //After the condition of the second 'for' loop becomes invalid, we print a new line.

        if(i == height)     //When we reach the maximum height, we have to reverse the pyramid.
        {
            reverse(height, character);
        }
    }

    return 0;
}
