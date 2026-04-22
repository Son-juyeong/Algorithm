#include<iostream>

using namespace std;

int dp[10001] = { 1 };

int main()
{
	int t, n, m;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		int v[20];
		for (int j = 0; j < n; j++)
			cin >> v[j];
		cin >> m;
		for (int j = 0; j < n; j++) {
			for (int k = v[j]; k <= m; k++)
				dp[k] += dp[k - v[j]];
		}
		cout << dp[m] << "\n";
		if (i == t - 1)
			break;
		for (int j = 1; j <= m; j++)
			dp[j] = 0;
	}
}