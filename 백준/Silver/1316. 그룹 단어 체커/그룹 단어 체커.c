#include<stdio.h>

int group(char a[])
{
	int i = 1, k = 0;
	char w[101]="\0";
	w[k] = a[0];
	while (i < 100&&a[i] != '\0') {
		if (a[i] != a[i - 1]) {
			int j = 0;
			while (w[j] != '\0') {
				if (w[j] == a[i])
					return 0;
				j++;
			}
			k++;
			w[k] = a[i];
		}
		i++;
	}
	return 1;
}

int main()
{
	char word[101];
	int n, i, cnt = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", word);
		cnt += group(word);
	}
	printf("%d", cnt);
	return 0;
}