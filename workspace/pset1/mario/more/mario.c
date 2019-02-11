#include <stdio.h>
#include <cs50.h>
int main()
{
    int height, i, j;
    do
    {
        // printf("Enter pyramid height :");
        // scanf("%d",&height);
        // printf("%d\n",height);
        height = get_int("Height: ");
    }
    while ((height < 0) || (height > 23));
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < height - 1 - i; j++)
        {
            printf(" ");
        }
        for (j = 0; j < 1 + i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (j = 0; j < 1 + i; j++)
        {
            printf("#");
        }
        // for(j=0;j<height-1-i;j++){
        //     printf(" ");
        // }
        printf("\n");
    }
}