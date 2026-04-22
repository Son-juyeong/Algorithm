#include <stdio.h>

int main()
{
	int star;
	scanf("%d", &star);
	for (int i = 0; i < star; i++)
	{
		for (int j = 0; j < star-i-1; j++)
		{
			printf(" ");
		}
		for (int r = 0; r < i+1; r++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}