#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<string> s;
	vector<string> ps;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		s.push_back(tmp);
	}
	for (int i = 0; i < m; i++) {
		string tmp;
		cin >> tmp;
		ps.push_back(tmp);
	}

	sort(s.begin(), s.end());

	int cnt = 0;

	for (int i = 0; i < m; i++) {
		int a = 0; int b = s.size()-1;
		while (1) {
			if (abs(a - b) <= 1) {
				if (s[a].compare(0, ps[i].length(), ps[i]) == 0 || s[b].compare(0, ps[i].length(), ps[i]) == 0)
					cnt++;
				break;
			}
			int j = (a + b) / 2;
			if (s[j].compare(0, ps[i].length(), ps[i]) == 0) {
				cnt++;
				break;
			}
			else if (s[j].compare(0, ps[i].length(), ps[i]) < 0) {
				a = j;
			}
			else {
				b = j;
			}
		}
	}

	cout << cnt << "\n";
}