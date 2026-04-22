#include<iostream>
using namespace std;

int dp[31] = { 1,0,3 };

int main()
{
	int n;
	cin >> n;
	int sum = 1;
	for (int i = 4; i <= n; i += 2) {
		dp[i] += dp[i - 2] * 3 + sum * 2;
		sum += dp[i - 2];
	}
	cout << dp[n] << endl;
}