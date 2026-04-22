#include<iostream>

using namespace std;

#define SZ 1000001
#define MOD 1000000009

long long dp[SZ] = { 0,1,2,4 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 4; i < SZ; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]  + dp[i - 3]) % MOD;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		cout << dp[t] << "\n";
	}
}