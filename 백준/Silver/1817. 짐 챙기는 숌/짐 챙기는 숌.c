#include<stdio.h>
#include<stdlib.h>


int main() {
	int i, n, m, k=0, s=0;
	
	scanf("%d %d", &n, &m);

	int* b = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		scanf("%d", &b[i]);

	for (i = 0; i < n; i++) {
		s += b[i];
		if (s == m) {
			s = 0;
			k++;
			continue;
		}
		else if (s > m) {
			s = 0;
			k++;
			--i;
			continue;
		}
		else
			if (i == n - 1)
				k++;
	}

	printf("%d", k);

	return 0;
}