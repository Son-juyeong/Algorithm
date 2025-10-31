#pragma warning(disable :4996)
#include<iostream>
#include<algorithm>

int dp[100001];

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	dp[0] = 0;
	dp[1] = dp[2] = dp[5] = dp[7] = 1;

	int n;
	cin >> n;

	for (int i = 2; i <=n; i++) {
		if (dp[i] == 1)
			continue;
		if (i < 5)
			dp[i] = min(dp[1] + dp[i - 1], dp[2] + dp[i - 2]);
		else if (i < 7)
			dp[i] = min({ dp[1] + dp[i - 1], dp[2] + dp[i - 2] , dp[5] + dp[i - 5] });
		else
			dp[i] = min({ dp[1] + dp[i - 1], dp[2] + dp[i - 2] , dp[5] + dp[i - 5], dp[7] + dp[i - 7] });
	}
	cout << dp[n] << endl;
}