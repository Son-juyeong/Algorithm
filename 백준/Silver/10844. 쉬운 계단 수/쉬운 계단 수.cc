#include<iostream>

using namespace std;
long long dp[101][10] = { 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const long long mod = 1000000000;

	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			switch (j) {
			case 0:
				dp[i][j] = dp[i - 1][1];
				break;
			case 9:
				dp[i][j] = dp[i - 1][8];
				break;
			default:
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
				break;
			}
			dp[i][j] %= mod;
		}
	}

	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += dp[n][i];
		sum %= mod;
	}
	cout << sum<< endl;
}