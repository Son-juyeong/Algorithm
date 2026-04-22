#include<stdio.h>

int main()
{
	int i = 0;
	int nn[10] = {0};
	char n[11];
	scanf("%s", n);
	while (n[i] != NULL) {
		if (n[i] == '0')
			nn[0]++;
		else if (n[i] == '1')
			nn[1]++;
		else if (n[i] == '2')
			nn[2]++;
		else if (n[i] == '3')
			nn[3]++;
		else if (n[i] == '4')
			nn[4]++;
		else if (n[i] == '5')
			nn[5]++;
		else if (n[i] == '6')
			nn[6]++;
		else if (n[i] == '7')
			nn[7]++;
		else if (n[i] == '8')
			nn[8]++;
		else if (n[i] == '9')
			nn[9]++;
		i++;
	}
	for (i = 9; i >= 0; i--) {
		for (int j = 0; j < nn[i]; j++)
			printf("%d", i);
	}
	return 0;
}