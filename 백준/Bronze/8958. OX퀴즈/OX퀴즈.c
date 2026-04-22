#include<stdio.h>

int main()
{
	int i, c, j;
	int score[100]={0};
	char answer[81] = { NULL };
	scanf("%d ", &c);
	for (i = 0; i <c; i++) {
		gets(answer);
		int s = 0;
		for (j = 0; answer[j] != NULL; j++) {
			if (answer[j] == 'X') {
				s = 0;
			}
			else {
				s++;
				score[i] += s;
			}
		}
	}
	for (i = 0; i < c; i++)
		printf("%d\n", score[i]);
	return 0;
}