#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	double j[3];
	double b[3];

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> j[0] >> j[1] >> j[2] >> b[0] >> b[1] >> b[2];
		double d = sqrt(pow(j[0] - b[0], 2.0) + pow(j[1] - b[1], 2.0));
		double big, small;
		if (j[2] >= b[2])
		{
			big = j[2];
			small = b[2];
		}
		else {
			big = b[2];
			small = j[2];
		}

		if (big == small && d == 0)
			cout << -1 << "\n";
		else if (d > big + small || d < big - small)
			cout << 0 << "\n";
		else if (d == big + small || d == big - small)
			cout << 1 << "\n";
		else if (big - small < d && d < big + small)
			cout << 2 << "\n";
	}

}