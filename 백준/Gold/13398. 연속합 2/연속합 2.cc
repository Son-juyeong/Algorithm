#include<iostream>
#include<algorithm>
using namespace std;

int dp[100000];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> dp[i];
	int tmp1 = 0;
	int tmp2 = 0;
	int answer = -1001;
	for (int i = 0; i < n; i++) {
		tmp1 += dp[i];
		if (dp[i] >= 0) {
			tmp2 += dp[i];
			answer = max({ answer, tmp1, tmp2 });
		}
		else {
			tmp2 = max(tmp2+dp[i], tmp1 - dp[i]);
			if (answer < 0) answer = max(answer, tmp1);
			else answer = max({ answer, tmp1, tmp2 });
			if (tmp1 < 0) tmp1 = 0;
		}
	}
	cout << answer << endl;
}