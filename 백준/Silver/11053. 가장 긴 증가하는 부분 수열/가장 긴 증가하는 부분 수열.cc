#include<iostream>
#include<cmath>

using namespace std;

#define SZ 1000

int dp[SZ];
int s[SZ];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int answer = 0;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (s[i] > s[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		if (dp[i] == 0)
			dp[i]++;
		answer = max(answer, dp[i]);
	}
	cout << answer << endl;
}