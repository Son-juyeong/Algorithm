#include<iostream>

using namespace std;

#define mod 10007
#define sz 1000

int dp[sz] = { 1,2 };

int main()
{
	int n;
	cin >> n;
	for (int i = 2; i < n; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % mod;
	}
	cout << dp[n - 1] << endl;
}