#include<stdio.h>
#define max(a, b) a>b?a:b

int main()
{
	char h[51];
	char DNA[1000][51];
	int n, m, i, cnt=0;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%s", &DNA[i]);
	}
	for (i = 0; i < m; i++) {
		int t = 0, a = 0, g = 0, c = 0;
		for (int j = 0; j < n; j++) {
			if (DNA[j][i] == 'T')
				t++;
			else if (DNA[j][i] == 'A')
				a++;
			else if (DNA[j][i] == 'G')
				g++;
			else
				c++;
		}
		int ma = max(t, a);
		ma = max(ma, g);
		ma = max(ma, c);
		if (a == ma)
			h[i] = 'A';
		else if (c == ma)
			h[i] = 'C';
		else if (g == ma)
			h[i] = 'G';
		else if (t == ma)
			h[i] = 'T';
		for (int k = 0; k < n; k++)
			if (DNA[k][i] != h[i])
				cnt++;
	}
	for (i = 0; i < m; i++)
		printf("%c", h[i]);
	printf("\n%d\n", cnt);
}