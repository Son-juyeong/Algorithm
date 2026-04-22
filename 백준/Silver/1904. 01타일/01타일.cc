#include<iostream>

using namespace std;

int dp[1000001] = { 1, 1 };
#define MOD 15746

int main()
{
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}
	cout << dp[n] << endl;
}