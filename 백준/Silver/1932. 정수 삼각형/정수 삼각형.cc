#include<iostream>
#define SZ 500
using namespace std;

int dp[SZ][SZ];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, answer = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			cin >> dp[i - 1][j];
			if (i == 1) continue;
			if (j == 0)
				dp[i - 1][j] += dp[i - 2][j];
			else if (j == i - 1)
				dp[i - 1][j] += dp[i - 2][j - 1];
			else dp[i - 1][j] += max(dp[i - 2][j], dp[i - 2][j - 1]);
		}
	}
	for (int i = 0; i < n; i++)
		answer = max(answer, dp[n - 1][i]);
	cout << answer << endl;
}