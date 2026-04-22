#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> v;
int dp[100] = { 1 };

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	int answer = 0;
	sort(v.begin(), v.end());
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i].second > v[j].second)
				dp[i] = max(dp[i], dp[j] + 1);
		}
		if (dp[i] == 0) dp[i] = 1;
		answer = max(answer, dp[i]);
	}
	cout << n - answer << endl;
}