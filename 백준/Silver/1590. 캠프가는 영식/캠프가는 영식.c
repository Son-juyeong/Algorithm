#include<stdio.h>
#include<math.h>

struct bus {
	int s;
	int i;
	int c;
};

int main() {
	struct bus wbus[50]={0};
	int n, t, j, min=pow(2, 31)-1, k, l=0;
	scanf("%d %d", &n, &t);
	for (j = 0; j < n; j++) {
		scanf("%d %d %d", &wbus[j].s, &wbus[j].i, &wbus[j].c);
		for (k = 0; k < wbus[j].c; k++) {
			if (t <= wbus[j].i * k + wbus[j].s) {
				++l;
				min = (wbus[j].i * k + wbus[j].s - t < min ? wbus[j].i * k + wbus[j].s - t : min);
				break;
			}
		}
	}
	if (l == 0)
		min = -1;
	
	printf("%d", min);
	return 0;
}