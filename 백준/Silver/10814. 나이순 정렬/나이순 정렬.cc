#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<tuple<int, int, string>> p;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		string nt;
		cin >> t >> nt;
		p.push_back({ t, i, nt });
	}
	sort(p.begin(), p.end());
	for (int i = 0; i < n; i++)
		cout << get<0>(p[i]) << " " << get<2>(p[i]) << "\n";
}