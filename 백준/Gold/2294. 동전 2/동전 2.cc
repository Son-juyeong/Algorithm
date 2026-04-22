#include<iostream>
#include<algorithm>

using namespace std;

int dp[10001];
int arr[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr + n+1);

	for (int i = 1; i <= k; i++) {
		dp[i] = 10001;
		for (int j = 1; j <= n; j++) {
			if (arr[j] > i) {
				if(dp[i] == 10001)
					dp[i] = -1;
				break;
			}
			else if (arr[j] == i) {
				dp[i] = 1;
				break;
			}
			else {
				if (dp[i - arr[j]] != -1&&dp[arr[j]]!=-1) {
					dp[i] = min(dp[i], dp[i - arr[j]] + dp[arr[j]]);
				}
			}
		}
		if (dp[i] == 10001)
			dp[i] = -1;
	}

	cout << dp[k] << endl;
}