#include <stdio.h>
#include<stdlib.h>

struct apart{
	int a;
	int b;
	int human;
};

int h;

int peo(int a, int b) {
	int i;
	if (a == 1) {
		for (i = 1; i <= b; i++)
			h += i;
	}
	else
		for (i = 1; i <= b; i++)
			peo(a - 1, i);

	return h;
}

int main()
{
	int t, i;
	scanf("%d", &t);
	struct apart *p=malloc(sizeof(struct apart)*t);
	for (i = 0; i < t; i++) {
		scanf("%d", &p[i].a);
		scanf("%d", &p[i].b);
		h = 0;
		p[i].human = peo(p[i].a, p[i].b);
	}

	for (i = 0; i < t; i++)
		printf("%d\n", p[i].human);
	
	free(p);

	return 0;
}
