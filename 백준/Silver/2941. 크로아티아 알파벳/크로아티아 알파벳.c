#include <stdio.h>

int main()
{
	char word[100];
	scanf("%s", word);
	int i = 0, count = 0, count2 = 0;
	while (word[i] != NULL)
	{
		if (((word[i] == 'c' || word[i] == 's' || word[i] == 'z') && word[i + 1] == '=') || ((word[i] == 'c' || word[i] == 'd') && word[i + 1] == '-') || ((word[i] == 'l' || word[i] == 'n') && word[i + 1] == 'j') || word[i] == 'd' && word[i + 1] == 'z' && word[i + 2] == '=')
			count++;
		count2++;
		i++;
	}
	printf("%d", count2-count);
	return 0;
}
