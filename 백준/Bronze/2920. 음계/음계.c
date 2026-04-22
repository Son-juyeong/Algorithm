#include<stdio.h>

int main()
{
    int mel[8];
    int wa = 0;
    int wd = 0;
    int a[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int d[8] = { 8, 7, 6, 5, 4, 3, 2, 1 };
    for (int i = 0; i < 8; i++) {
        scanf("%d", &mel[i]);
        if (mel[i] == a[i])
            wa++;
        else if (mel[i] == d[i])
            wd++;
    }
    if (wa == 8)
        printf("ascending\n");
    else if (wd == 8)
        printf("descending\n");
    else
        printf("mixed\n");
    return 0;
}