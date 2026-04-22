#include <stdio.h>
#include<stdlib.h>

struct data{
	int h;
	int w;
	int n;
	int room;
};

int main()
{
	int t, i;
	scanf("%d", &t);
	struct data *r=malloc(sizeof(struct data)*t);
	for (i = 0; i < t; i++) {
		scanf("%d %d %d", &r[i].h, &r[i].w, &r[i].n);
		int x;
		if (r[i].n % r[i].h == 0)
			x = r[i].n / r[i].h;
		else
			x = r[i].n / r[i].h + 1;
		int y;
		if (r[i].n % r[i].h == 0)
			y = r[i].h;
		else
			y = r[i].n % r[i].h;
		r[i].room = 100 * y + x;
	}
	for (i = 0; i < t; i++)
		printf("%d\n", r[i].room);

	free(r);

	return 0;
}
