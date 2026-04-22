#include<iostream>

using namespace std;

int dp[300][2] = { 0 };

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (i == 0) {
			dp[0][0] = t;
			dp[0][1] = t;
		}
		else if (i == 1) {
			dp[1][0] = t;
			dp[1][1] = dp[0][0] + t;
		}
		else {
			dp[i][0] = max(dp[i - 2][1] + t, dp[i-2][0]+t);
			dp[i][1] = dp[i - 1][0] + t;
		}
	}

	cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
}