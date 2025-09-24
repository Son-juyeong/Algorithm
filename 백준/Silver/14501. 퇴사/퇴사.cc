#include<iostream>
#include<cmath>

using namespace std;

int dp[16];
int T[16];
int P[16];

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i];
		cin >> P[i];
	}

	for (int i = 1; i <= N; i++) {
		int t = T[i];
		int p = P[i];
		int temp = 0;
		for (int j = 1; j < i; j++) {
			temp = max(dp[j], temp);
		}
		if (i + t-1 <= N) {
			dp[i + t-1] = max(dp[i + t-1], temp + p);
		}
	}
	
	int answer = 0;

	for (int i = 1; i <= N; i++) {
		answer = max(dp[i], answer);
	}

	cout << answer;

	return 0;
}