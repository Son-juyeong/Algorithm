#include<iostream>
#include<algorithm>

using namespace std;

int dp[10001] = { 1 };
int value[100] = { 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> value[i];

	sort(value, value + n);
	
	for (int i = 0; i < n; i++) {
		for (int j = value[i]; j <= k; j++)
			dp[j] += dp[j - value[i]];
	}

	cout << dp[k] << endl;
}