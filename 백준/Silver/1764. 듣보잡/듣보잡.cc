#include<iostream>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	set<string> p1;
	vector<string> p2;

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		p1.insert(s);
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (p1.find(s) != p1.end())
			p2.push_back(s);
	}

	sort(p2.begin(), p2.end());

	cout << p2.size() << "\n";
	for (int i = 0; i < p2.size(); i++)
		cout << p2[i] << "\n";

}