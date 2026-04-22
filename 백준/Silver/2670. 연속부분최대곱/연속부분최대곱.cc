#include<iostream>

using namespace std;
long double dp[10000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	long double nmax = 0, tmax = 1.0;
	for (int i = 0; i < n; i++) {
		cin >> dp[i];
		tmax *= dp[i];
		nmax = max(nmax, tmax);
		if (tmax < 1)
			tmax = 1.0;
	}
	cout << fixed;
	cout.precision(3);
	cout << nmax << endl;
}