#include<iostream>

using namespace std;

#define mod 1000000009
#define sz 100000

int dp[sz][3] = { {1, 0, 0}, {0, 1, 0}, {1, 1, 1} };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 3; i < sz; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % mod;
		dp[i][1] = (dp[i - 2][0] + dp[i - 2][2]) % mod;
		dp[i][2] = (dp[i - 3][1] + dp[i - 3][0]) % mod;
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int answer=0;
		for (int j = 0; j < 3; j++) {
			answer += dp[n - 1][j];
			answer %= mod;
		}
		cout << answer << endl;
	}
}