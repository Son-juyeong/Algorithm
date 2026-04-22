#include<iostream>

using namespace std;

int dp[1001][1001] = { 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string a;
	string b;

	cin >> a;
	cin.ignore();
	cin >> b;

	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	string s = "\0";
	int i = a.size();
	int j = b.size();
	while (i >0 && j >0) {
		if (a[i - 1] == b[j - 1]) {
			s += a[i - 1];
			i--; j--;
		}
		else {
			if (dp[i - 1][j] > dp[i][j - 1])
				i--;
			else if (dp[i - 1][j] == dp[i][j - 1]) {
				if (i > j)
					i--;
				else
					j--;
			}
			else
				j--;
		}
	}

	cout << dp[a.size()][b.size()] << endl;
	for (int i = s.size() - 1; i >= 0; i--)
		cout << s[i];
}