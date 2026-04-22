#include<stdio.h>

int main() {
	int e, s, m, year=0, i;
	scanf("%d %d %d", &e, &s, &m);
	if ((e == s)&&(s == m)) {
		if (e == 1)
			year = 1;
		else
			year = e;
	}
	else
	{
			for (i = 1; i <= 7980; i++) {
					if ((e == 15) && (m == 19) && (s == 28)&&(i % e == 0)&&(i % m == 0)&&(i % s == 0)) {
						year = i;
						break;
					}
					else if (((e == 15 )&& (i % e == 0) && (m == 19 )&& (i % m == 0)&&(i%28==s)) || ((e == 15 )&& (i % e == 0) && (s == 28) && (i % s == 0)&&(i%19==m)) || ((s == 28 )&&( i % s == 0) && (m == 19) &&( i % m == 0)&&(i%15==e))) {
						year = i;
						break;
					}
					else if (((e == 15) && (i % e == 0)&&(i%19==m)&&(i%28==s))|| ((m == 19 )&& (i % m == 0) && (i % 15 == e) && (i % 28 == s))|| ((s == 28) && (i % s == 0) && (i % 19 == m) && (i % 15 == e))) {
						year = i;
						break;
					}
				else if ((i % 15 == e) && (i % 19 == m) && (i % 28 == s))
				{
					year = i;
						break;
				}
			}
		}
	printf("%d", year);
	return 0;
}