#include <stdio.h>

int main()
{
    int a, b, c, d;
    scanf("%d %d %d", &a, &b, &c);

    if (c > b) {
        d = a / (c - b) + 1;
    }
    else
        d = -1;

    printf("%d", d);
    return 0;
}