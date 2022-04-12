#include <stdio.h>

int main()
{
    int num;
    int i,j;

    scanf("%d", &num);
    for(i = 1;i <= num;i++)
    {
        for(j = 0;j < num - i;j++)
            printf(" ");
        for(;j < num;j++)
            printf("*");
        printf("\n");
    }    
    return 0;
}