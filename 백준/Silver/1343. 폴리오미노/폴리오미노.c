#include<stdio.h>

int main()
{
	int i = 0, n = 0, j;
	char board[50] = { '\0' };
	scanf("%s", board);
	while (board[i] != '\0') {
		if (board[i] == 'X') {
			n++;
		}
		else if (board[i] == '.') {
			if (n == 0)
			{
				i++; continue;
			}
			if (n % 2 == 0) {
				if ((n / 2) % 2 == 0)
					for (j = 1; j <=n; j++)
						board[i - j] = 'A';
				else
				{
					board[i - 1] = board[i - 2] = 'B';
					for (j = 3; j <=n; j++)
						board[i - j] = 'A';
				}
			}
			else {
				printf("-1\n"); return 0;
			}
			n = 0;
		}
		if (board[i + 1] == '\0') {
			if (n % 2 == 0) {
				if ((n / 2) % 2 == 0)
					for (j = 0; j < n; j++)
						board[i - j] = 'A';
				else
				{
					board[i] = board[i - 1] = 'B';
					for (j = 2; j < n; j++)
						board[i - j] = 'A';
				}
			}
			else {
				printf("-1\n"); return 0;
			}
		}
		i++;
	}
	i = 0;
	while (board[i] != '\0') {
		printf("%c", board[i]);
		i++;
	}
	return 0;
}