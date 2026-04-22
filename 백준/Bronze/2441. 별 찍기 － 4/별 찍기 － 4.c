#include<stdio.h>
int main(void)
{
    int num, i, k ,j;
    scanf("%d", &num);
    for(i=1;i<=num;i++)
    {
        for(j=0;j<i-1;j++)
            printf(" ");
        for(k=num;k>j;k--)
            printf("*");
        printf("\n");
    }
    return 0;
}