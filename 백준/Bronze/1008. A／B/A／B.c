#include<stdio.h>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	if (a % b == 0)
		printf("%d", a / b);
	else {
		double c = (double)a / b;
		printf("%.9f", c);
	}
	return 0;
}