#include <stdio.h>

int main()
{
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	if (b - 45 < 0)
	{
		b = 60 + (b - 45);
		a = a - 1;
		if (a == -1)
			a = 23;
	}
	else
	{
		b = b - 45;
	
	}
	printf("%d %d", a, b);
	return 0;
}