#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;

int main()
{
	vector<tuple<int, int, int, string>> p;
	int n, y, m, d;
	string name;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name >> d >> m >> y;
		p.push_back({ y, m, d, name });
	}
	sort(p.begin(), p.end());
	cout << get<3>(p[n - 1]) << endl;
	cout << get<3>(p[0]) << endl;
}