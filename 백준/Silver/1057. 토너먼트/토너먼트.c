#include<stdio.h>

int round(int n, int k, int l, int r)
{
	if (k % 2 == 1 && k + 1 == l)
		return r;
	if (n % 2 == 1) {
		n = n / 2 + 1;
		if (k % 2 == 1)
			k = k / 2 + 1;
		else
			k = k / 2;
		if (l % 2 == 1)
			l = l / 2 + 1;
		else
			l = l / 2;
		r++;
		round(n, k, l, r);
	}
	else {
		n = n / 2;
		if (k % 2 == 1)
			k = k / 2 + 1;
		else
			k = k / 2;
		if (l % 2 == 1)
			l = l / 2 + 1;
		else
			l = l / 2;
		r++;
		round(n, k, l, r);
	}
}

int main()
{
	int n, k, l, i, r=1;
	scanf("%d %d %d", &n, &k, &l);
	if (k < l)
		r = round(n, k, l, r);
	else if (k > l)
		r = round(n, l, k, r);
	printf("%d", r);
	return 0;
}