#include<stdio.h>

int main()
{
	int n;
	int cnt = 0;
	scanf("%d", &n);
	while (1) {
		if (n % 5 == 0) {
			printf("%d", cnt+n / 5);
			return 0;
		}
		n -= 3;
		cnt++;
		if (n == 0) {
			printf("%d", cnt);
			return 0;
		}
		else if (n < 0)
			break;
	}
	printf("-1");
	return 0;
}