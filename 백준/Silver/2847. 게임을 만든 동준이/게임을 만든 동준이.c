#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, i, s = 0;
	scanf("%d", &n);
	int* score = malloc(sizeof(int) * n);
	int* rscore = malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		scanf("%d", &score[i]);
		rscore[i] = score[i];
	}
	for (i = n - 1; i > 0; i--) {
		if (rscore[i] <= rscore[i - 1]) {
			rscore[i - 1] = rscore[i] - 1;
			s += score[i - 1] - rscore[i - 1];
		}
	}
	printf("%d", s);
	return 0;
}