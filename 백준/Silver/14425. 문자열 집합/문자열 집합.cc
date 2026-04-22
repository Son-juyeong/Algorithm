#include<iostream>
#include<set>

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int cnt = 0;
	int n, m;
	cin >> n >> m;

	set<string>s;

	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		s.insert(t);
	}

	for (int i = 0; i < m; i++) {
		string tmp;
		cin >> tmp;
		if (s.find(tmp) != s.end())
			cnt++;
	}
	cout << cnt << endl;
}