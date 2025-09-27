#include<iostream>
#include<cmath>

using namespace std;

int dp[201];
int arr[201];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	
	int answer = n;
	for (int i = 1; i <= n; i++) {
		answer = min(answer, n - dp[i]);
	}

	cout << answer;

	return 0;
}