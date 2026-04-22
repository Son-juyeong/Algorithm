#include<stdio.h>

int main()
{
    int num[9];
    int maxi = 0, ind = 0;
    for (int i = 0; i < 9; i++)
        scanf("%d", &num[i]);
    for (int i = 0; i < 9; i++) {
        if (maxi < num[i]) {
            maxi = num[i];
            ind = i + 1;
        }
    }
    printf("%d\n%d", maxi, ind);
    return 0;
}