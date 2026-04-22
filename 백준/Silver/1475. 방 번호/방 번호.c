#include<stdio.h>
#include<string.h>
#define max(a, b) a>b?a:b

int main()
{
	char room[8] = "\0";
	scanf("%s", room);
	int num[10] = { 0 };
	int cnt = 0;
	for (int i = 0; i < strlen(room); i++) {
		int n = room[i] - '0';
		num[n]++;
	}
	if ((num[6] + num[9]) % 2 == 0) {
		num[6] = (num[6] + num[9]) / 2;
		num[9] = 0;
	}
	else {
		num[6] = (num[6] + num[9]) / 2 + 1;
		num[9] = 0;
	}
	for (int i = 0; i < 9; i++) {
		cnt = max(cnt, num[i]);
	}
	printf("%d", cnt);
	return 0;
}