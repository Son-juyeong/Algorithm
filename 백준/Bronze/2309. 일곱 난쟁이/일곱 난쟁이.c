#include<stdio.h>

int main()
{
	int totalh = 0;
	int h[9] = { 0 };
	for (int i = 0; i < 9; i++) {
		scanf("%d", &h[i]);
		totalh += h[i];
	}
	int m1, m2, c = 0;
	totalh -= 100;
	for (int i = 0; i < 8; i++) {
		int cnt = 0;
		for (int j = 0; j < 8 - i; j++) {
			if (h[j] > h[j + 1]) {
				int tmp = h[j];
				h[j] = h[j + 1];
				h[j + 1] = tmp;
				cnt++;
			}
		}
		if (cnt == 0)
			break;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (totalh == h[i] + h[j]) {
				m1 = i;
				m2 = j;
				c = 1;
				break;
			}
		}
		if (c)
			break;
	}
	for (int i = 0; i < 9; i++) {
		if (i == m1 || i == m2)
			continue;
		printf("%d\n", h[i]);
	}
	return 0;
}