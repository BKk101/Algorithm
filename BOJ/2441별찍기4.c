#include <stdio.h>

int main()
{
    int num;
    int i,j;

    scanf("%d", &num);
    for(i = 0;i < num;i++)
    {
        for(j = 0;j < i;j++)
            printf(" ");
            
        for(;j < num;j++)
            printf("*");
        printf("\n");
    }    
    return 0;
}