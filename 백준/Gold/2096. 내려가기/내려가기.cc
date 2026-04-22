#include<iostream>
#include<algorithm>

using namespace std;

int dp[2][6];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> dp[i % 2][j * 2];
			dp[i % 2][j * 2 + 1] = dp[i % 2][j * 2];
		}
		if (i != 0) {
			dp[i % 2][0] += max({ dp[(i + 1) % 2][0], dp[(i + 1) % 2][2] });
			dp[i % 2][1] += min({ dp[(i + 1) % 2][1], dp[(i + 1) % 2][3] });
			dp[i % 2][2] += max({ dp[(i + 1) % 2][0], dp[(i + 1) % 2][2], dp[(i + 1) % 2][4] });
			dp[i % 2][3] += min({ dp[(i + 1) % 2][1], dp[(i + 1) % 2][3], dp[(i + 1) % 2][5] });
			dp[i % 2][4] += max({ dp[(i + 1) % 2][4], dp[(i + 1) % 2][2] });
			dp[i % 2][5] += min({ dp[(i + 1) % 2][5], dp[(i + 1) % 2][3] });
		}
	}
	cout << max({ dp[(n - 1) % 2][0], dp[(n - 1) % 2][2], dp[(n - 1) % 2][4] }) << " " << min({ dp[(n - 1) % 2][1], dp[(n - 1) % 2][3], dp[(n - 1) % 2][5] }) << endl;
}