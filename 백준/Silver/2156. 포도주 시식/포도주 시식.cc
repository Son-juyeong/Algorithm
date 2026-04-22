#include<iostream>
#include<algorithm>

using namespace std;

int dp[10000][2] = { 0 };

int main() {
	int n;
	cin >> n;
	int maxnum = 0;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (i == 0) {
			dp[i][0] = t;
			dp[i][1] = t;
		}
		else if (i == 1) {
			dp[i][0] = t;
			dp[i][1] = t + dp[0][0];
		}
		else {
			dp[i][0] = max({ t + max(dp[i - 2][0], dp[i - 2][1]), max(dp[i - 1][0], dp[i - 1][1]) });
			dp[i][1] = t + dp[i - 1][0];
		}
		maxnum = max({ maxnum ,dp[i][0], dp[i][1] });
	}
	cout << maxnum << endl;
}
