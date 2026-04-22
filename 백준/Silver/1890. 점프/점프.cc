#include<iostream>

using namespace std;

#define SZ 100

int arr[SZ][SZ];
long long dp[SZ][SZ] = { 1 };

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if ((arr[i][j] == 0 || dp[i][j] == 0))
				continue;
			if (i + arr[i][j] < n)
				dp[i + arr[i][j]][j] += dp[i][j];
			if (j + arr[i][j] < n)
				dp[i][j + arr[i][j]] += dp[i][j];
		}

	cout << dp[n - 1][n - 1] << endl;
}