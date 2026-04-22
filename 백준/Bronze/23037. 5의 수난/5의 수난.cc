#include<stdio.h>
#include<math.h>
int main(void)
{
    int num;
    scanf("%d", &num);
    int a = pow(num / 10000, 5);
    num %= 10000;
    int b = pow(num / 1000, 5);
    num %= 1000;
    int c = pow(num / 100, 5);
    num %= 100;
    int d = pow(num / 10, 5);
    num %= 10;
    int e = pow(num, 5);
    printf("%d", a+b+c+d+e);
    return 0;
}