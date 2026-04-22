#include <stdio.h>

int main()
{
	int n, i;
	int f[46];

	f[0] = 0;
	f[1] = 1;

	scanf("%d", &n);

	for (i = 2; i < 46; i++)
		f[i] = f[i - 1] + f[i - 2];

	printf("%d", f[n]);

	return 0;
}
