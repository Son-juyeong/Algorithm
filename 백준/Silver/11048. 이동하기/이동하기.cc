#include<iostream>
#include<algorithm>

using namespace std;

int dp[1000][1000];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> dp[i][j];
			if (i == 0) {
				if (j != 0)
					dp[i][j] += dp[i][j - 1];
			}
			else {
				if (j == 0)
					dp[i][j] += dp[i - 1][j];
				else {
					dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
	}
	cout << dp[n - 1][m - 1] << endl;
}