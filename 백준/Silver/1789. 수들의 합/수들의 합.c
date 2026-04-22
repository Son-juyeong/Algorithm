#include<stdio.h>

int main()
{
	long long n, sum=0, i;
	scanf("%lld", &n);
	for (i = 1; i <= n; i++) {
		sum += i;
		if (sum == n)
			break;
		else if (sum > n) {
			--i;
			break;
		}
	}
	printf("%d", i);
	return 0;
}