#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	set<int> s;
	int a, b, cnt = 0;
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		int c;
		cin >> c;
		s.insert(c);
	}
	for (int i = 0; i < b; i++) {
		int c;
		cin >> c;
		if (s.find(c) != s.end())
			cnt+=2;
	}
	cout << a + b - cnt << endl;
}