#include<iostream>

using namespace std;

#define sz 10

int main()
{
	int dp[sz] = { 1,2,4 };
	for (int i = 3; i < sz; i++) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << dp[n - 1] << endl;
	}
}