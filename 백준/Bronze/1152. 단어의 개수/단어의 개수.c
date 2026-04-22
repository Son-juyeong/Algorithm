#include<stdio.h>
#include<string.h>

int main()
{
	char word[1000001];
	gets(word);
	int a = 0;
	for (int i = 0; i < strlen(word); i++) {
		if (word[i] == ' ')
			a++;
	}
	if (word[0] == ' ')
		a--;
	if (word[strlen(word) - 1] == ' ')
		a--;
	printf("%d", a+1);
	return 0;
}