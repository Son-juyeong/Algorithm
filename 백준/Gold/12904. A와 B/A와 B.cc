#include<iostream>
#include<algorithm>
using namespace std;

string s, t;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> s;
	cin.ignore();
	cin >> t;

	while (s.size() < t.size()) {
		char tmp = t.back();
		t.pop_back();
		if (tmp == 'B') reverse(t.begin(), t.end());
	}
	if (s == t) cout << "1\n";
	else cout << "0\n";
}