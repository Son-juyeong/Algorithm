#include<iostream>
#define MAX 31
using namespace std;

long long dp[MAX] = { 1 };

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 1; i < MAX; i++) {
		for (int j = i; j < MAX; j++) {
			dp[j] += dp[j - 1];
		}
	}
	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;
		cout << dp[n] << "\n";
	}
}