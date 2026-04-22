#include <stdio.h>

int main()
{
	int num;
	scanf("%d", &num);
	int min = 1000001, max = -1000001;
	for(int i=0; i < num; ++i){
		int a;
		scanf("%d", &a);
		if (a < min)
			min = a;
		if (a > max)
			max = a;
	}
	printf("%d %d\n", min, max);
	return 0;
}