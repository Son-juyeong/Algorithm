#include<stdio.h>

void num(long long a) {
	for (long long i = 2; i <= a; i++) {
		if (a == 1)
			break;
		else if (a % i == 0) {
			printf("%d\n", i);
			num((a / i));
			break;
		}
	}
}

int main()
{
	long long n;
	scanf("%lld", &n);
	num(n);
	return 0;
}