#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void arr(int*** a, int n) {
	int i, k = 1, r = 0, c = 0, d = pow(n, 2), e = n - 1;
	for (n; n >= 1; n--) {
		if (k % 4 == 1) {
			for (i = 0; i < n; i++) {
				(*a)[r + i][c] = d--;
			}
			k++;
			continue;
		}
		else if (k % 4 == 2) {
			for (i = 0; i < n; i++) {
				(*a)[e - r][c + i + 1] = d--;
			}
			n++;
			k++;
			continue;
		}
		else if (k % 4 == 3) {
			for (i = 0; i < n; i++) {
				(*a)[e - i - r - 1][e - c] = d--;
			}
			c++;
			k++;
			continue;
		}
		else if (k % 4 == 0) {
			for (i = 0; i < n; i++) {
				(*a)[r][e - c - i] = d--;
			}
			r++;
			n++;
			k = 1;
			continue;
		}
	}
}

void print(int*** a, int n, int m) {
	int i, j, row = 0, col = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", (*a)[i][j]);
			if ((*a)[i][j] == m) {
				row = i + 1;
				col = j + 1;
			}
		}
		printf("\n");
	}
	printf("%d %d", row, col);
}

int main()
{
	int n, i, m;
	scanf("%d %d", &n, &m);
	int** snail =(int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
		*(snail+i) = (int*)malloc(sizeof(int) * n);
	arr(&snail, n);
	print(&snail, n, m);
	for (i = 0; i < n; i++) {
		free(snail[i]);
	}
	free(snail);
	return 0;
}