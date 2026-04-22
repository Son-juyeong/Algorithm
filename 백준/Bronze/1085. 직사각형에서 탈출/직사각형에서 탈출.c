#include<stdio.h>
#define min(a, b) a<b?a:b

int main()
{
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	int minn = min(x, y);
	minn = min(minn, w - x);
	minn = min(minn, h - y);
	printf("%d\n", minn);
	return 0;
}