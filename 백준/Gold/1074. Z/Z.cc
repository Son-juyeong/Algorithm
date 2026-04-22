#include<iostream>
#include<cmath>

using namespace std;

int g = 0;

void Z(int a, int b, int c, int d, int n) {
	if (a == c && b == d) { cout << g << endl; return; }
	if (a >= c && b >= d &&a<c+n&&b<d+n) {
		Z(a, b, c, d, n / 2);
		Z(a, b, c, d + n / 2, n / 2);
		Z(a, b, c + n / 2, d, n / 2);
		Z(a, b, c + n / 2, d + n / 2, n / 2);
	}
	else
		g += int(pow(n, 2));
}

int main()
{
	int n;
	cin >> n;
	int r, c;
	cin >> r >> c;

	int cnt = 0;
	Z(r, c, 0, 0, int(pow(2, n)));
}