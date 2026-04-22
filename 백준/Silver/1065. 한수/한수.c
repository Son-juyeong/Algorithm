#include<stdio.h>

int main() {
	int n, i, num=0;
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		if (n<100) {
			num = n;
			break;
		}
		else {
			if (i < 100) {
				num++;
				continue;
			}
			int s = (i % 1000) / 100;
			int d = ((i % 1000) % 100) / 10;
			int f = ((i % 1000) % 100) % 10;
			if (d - s == f - d || s - d == d - f)
				num++;
		}
	}
	if (n == 1000)
		--num;
	printf("%d", num);
	return 0;
}