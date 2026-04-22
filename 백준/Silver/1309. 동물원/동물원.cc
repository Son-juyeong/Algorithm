#include<iostream>
#include<algorithm>

using namespace std;

int dp[100000] = { 3, 7 };
#define MOD 9901

int main()
{
	int n;
	cin >> n;
	for (int i = 2; i < n; i++) {
		dp[i] = ((2 * dp[i - 1]) % MOD + dp[i - 2]) % MOD;
	}
	cout << dp[n - 1] << endl;
}