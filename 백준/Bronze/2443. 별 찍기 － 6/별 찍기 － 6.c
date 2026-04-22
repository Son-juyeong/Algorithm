#include<stdio.h>
int main(void)
{
    int num, i, k, j, a;
    scanf("%d", &num);
    for (i = num; i >0; i--)
    {
        for (j = num; j > i; j--)
            printf(" ");
        for (k = j; k>0;k--)
            printf("*");
        for (a = j; a > 1; a--)
            printf("*");
        printf("\n");
    }
    return 0;
}