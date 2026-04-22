#include<stdio.h>

int area(char a[50][50], int b, int c, int d) {
	int i, j;
	if (d == 1)
		return 1;
	for (i = 0; i <= b - d; i++) {
		for (j = 0; j <= c - d; j++) {
			if (a[i][j] == a[i + d-1][j] && a[i + d-1][j] == a[i + d-1][j + d-1] && a[i + d-1][j] == a[i][j + d-1])
				return d * d;
		}
	}
	return area( a, b, c, d - 1);
}

int main()
{
	int i, n, m, max=1;
	scanf("%d %d", &n, &m);
	char arr[50][50];
	for (i = 0; i < n; i++) {
		scanf("%s", arr[i]);
	}
	if (n < m)
		max = area(arr, n, m, n);
	else
		max = area(arr, n, m, m);

	printf("%d", max);
	return 0;
}