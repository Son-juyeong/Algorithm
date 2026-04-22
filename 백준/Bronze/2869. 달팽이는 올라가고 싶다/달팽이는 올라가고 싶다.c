#include <stdio.h>

int main()
{
	int a, b, v, day=0, m=0;
	scanf("%d %d %d", &a, &b, &v);
	day = (v-a) / (a - b)+1;
	if ((v - a) % (a - b) != 0)
		day++;
	printf("%d", day);
	return 0;
}
