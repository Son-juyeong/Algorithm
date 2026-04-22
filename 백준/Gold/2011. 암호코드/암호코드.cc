#include<iostream>

using namespace std;

int dp[5000] = { 0 };

#define MOD 1000000

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


		string s;
		cin >> s;
		bool error = false;
		for (int i = 0; i < s.size(); i++) {
			if (i == 0) {
				if (s[i] == '0') {
					error = true;
					break;
				}
				else
					dp[i] = 1;
			}
			else if (i == 1) {
				if (s[i] == '0') {
					if (s[i - 1] - '0' > 2) {
						error = true;
						break;
					}
					else
						dp[i] = dp[i - 1];
				}
				else if (s[i - 1] - '0' == 2 && s[i] - '0' < 7||s[i-1]=='1')
					dp[i] = 2;
				else
					dp[i] = dp[i - 1];
			}
			else {
				if (s[i] == '0') {
					if (s[i - 1] - '0' > 2 || s[i - 1] == '0') {
						error = true;
						break;
					}
					else
						dp[i] = dp[i - 2];
				}
				else if (s[i - 1] - '0' == 2 && s[i] - '0' < 7||s[i-1]=='1')
					dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
				else
					dp[i] = dp[i - 1];
			}
		}
		if (error)
			cout << 0 << endl;
		else
			cout << dp[s.size() - 1] << endl;
	
}