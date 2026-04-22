#include<stdio.h>

int main()
{
	int n, gender, p, c, j, k;
	int switches[100];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &switches[i]);
	scanf("%d", &p);
	for (int i = 0; i < p; i++) {
		scanf("%d %d", &gender, &c);
		if (gender == 1) {
			for (j = c - 1; j < n; j += c)
				if (switches[j] == 0)
					switches[j] = 1;
				else
					switches[j] = 0;
		}
		else if (gender == 2) {
			for (j = 1; j < n; j++) {
				if (switches[c - 1 - j] != switches[c - 1 + j]||c - 1 - j < 0 || c - 1 + j == n) {
					for (k = c - j; k < c - 1 + j; k++) {
						if (switches[k] == 0)
							switches[k] = 1;
						else
							switches[k] = 0;
					}
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", switches[i]);
		if ((i+1)%20==0)
			printf("\n");
	}
	return 0;
}