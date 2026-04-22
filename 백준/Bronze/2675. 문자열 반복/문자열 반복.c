#include<stdio.h>

int main()
{
	int t, r;
	char s[21];
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %s", &r, s);
		int j = 0;
		while (s[j] != '\0') {
			for(int k=0;k<r;k++)
				printf("%c", s[j]);
			j++;
		}
		printf("\n");
	}
	return 0;
}