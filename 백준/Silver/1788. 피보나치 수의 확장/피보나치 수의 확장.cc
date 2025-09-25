#include<iostream>
#include<cmath>
constexpr auto mod = 1000000000;

using namespace std;

long long dp[1000001];

int main()
{
	int n;
	cin >> n;
	dp[1] = 1;
	if (n > 0) {
		
		for (int i = 2; i <= n; i++) {
			dp[i] = (dp[i - 2] + dp[i - 1]) % mod;
		}
		
	}
	else if (n < 0) {

		for (int i = 2; i <= abs(n); i++) {
			dp[i] = (dp[i - 2] - dp[i - 1])%mod;
		}
	}

	n = abs(n);

	if (dp[n] > 0)
		cout << 1 << "\n";
	else if (dp[n] == 0)
		cout << 0 << "\n";
	else
		cout << -1 << "\n";

	cout << abs(dp[n]);

	return 0;
}