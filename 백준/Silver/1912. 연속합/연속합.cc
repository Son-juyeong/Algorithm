#include<iostream>
#include<algorithm>

int dp[100000];

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> dp[i];
	int max_sum = -2000;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		tmp += dp[i];
		max_sum = max(max_sum, tmp);
		if (tmp < 0)
			tmp = 0;
	}
	cout << max_sum << endl;
}