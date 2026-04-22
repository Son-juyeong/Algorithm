#include<stdio.h>

int main()
{
	int i, j, a, b, num = 0, c=0;

	scanf("%d %d", &a, &b);

	for (i = 1; i < 50; i++) {
		for (j=0; j < i; j++) {
			c++;
			if (c >= a) {
				num += i;
			}
			if (c == b) {
				printf("%d", num);
				return 0;
			}
		}
	}
}