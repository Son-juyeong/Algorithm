#include<iostream>
using namespace std;

struct knapsack {
	int weight;
	int value;
};

knapsack ks[101];
int dp[101][100001];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> ks[i].weight >> ks[i].value;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= ks[i].weight) dp[i][j] = max(dp[i - 1][j], dp[i-1][j - ks[i].weight] + ks[i].value);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][k] << endl;
}