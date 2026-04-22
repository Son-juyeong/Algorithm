#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int I = 0, O = 0, cnt = 0;
	for (int i = 0; i < m; i++) {
		if (s[i] == 'I') {
			if (i > 0 && s[i - 1] == 'I') {
				I = 1;
				O = 0;
			}
			else I++;
		}
		else if (s[i] == 'O') {
			if (i == 0 || i == m - 1 || (i > 0 && s[i - 1] == 'O')) {
				I = 0;
				O = 0;
			}
			else O++;
		}
		if (I == n + 1 && O == n) {
			cnt++;
			I -= 1;
			O -= 1;
		}
	}
	cout << cnt << endl;
}