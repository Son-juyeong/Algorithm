#include<stdio.h>

int main()
{
	int X, bar = 0;
	scanf("%d", &X);
	while (X != 0) {
		if (X % 2 == 1)
			bar++;
		X /= 2;
	}
	printf("%d", bar);
	return 0;
}