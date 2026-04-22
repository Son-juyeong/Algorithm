#include<stdio.h>
#include<stdlib.h>

int main()
{
	int c, n, m, i, l;
	scanf("%d", &c);
	long long* p = (long long*)malloc(sizeof(long long) * c);
	for (i = 0; i < c; i++) {
		scanf("%d %d", &n, &m);
		long long j = 1, k = 1;
		if (n > m / 2)
			n = m - n;
		for (l = 0; l < n; l++) {
			j *= m - l;
			k *= n - l;
		}
		p[i] = j / k;
	}
	for (i = 0; i < c; i++)
		printf("%lld\n", p[i]);

	free(p);
	return 0;
}