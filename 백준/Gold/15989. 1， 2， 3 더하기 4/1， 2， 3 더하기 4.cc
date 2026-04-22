#include<iostream>

using namespace std;

#define sz 10000

long long dp[sz][3] = { {1, 0, 0}, {1, 1, 0}, {1, 1, 1} };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 3; i < sz; i++) {
		dp[i][0] = dp[i - 1][0];
		dp[i][1] = dp[i - 2][0] + dp[i - 2][1];
		dp[i][2] = dp[i - 3][0] + dp[i - 3][1] + dp[i - 3][2];
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int answer=0;
		for (int j = 0; j < 3; j++) {
			answer += dp[n - 1][j];
		}
		cout << answer << "\n";
	}
}