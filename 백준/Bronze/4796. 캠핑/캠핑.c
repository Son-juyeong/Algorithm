#include<stdio.h>
#define min(a,b) a<b?a:b

int main()
{
	int l, p, v, j = 1;
	while (1) {
		scanf("%d %d %d", &l, &p, &v);
		if (l == 0 && p == 0 && v == 0)
			break;
		int a = min(v % p, l);
		int maax = (v / p) * l + a;
		printf("Case %d: %d\n", j, maax);
		j++;
	}
	return 0;
}