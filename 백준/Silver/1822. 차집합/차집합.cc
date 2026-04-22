#include<iostream>
#include<set>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	set<int> a;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		a.insert(t);
	}

	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		if (a.find(t) != a.end())
			a.erase(a.find(t));
	}
	cout << a.size() << "\n";
	if(a.size()) {
		for (auto iter = a.begin(); iter != a.end(); iter++)
			cout << *iter << " ";
	}
}