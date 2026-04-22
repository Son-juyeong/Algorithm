#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> p;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int min;
		cin >> min;
		p.push_back(min);
	}
	sort(p.begin(), p.end());

	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += p[i] * (n - i);
	}

	cout << sum << endl;
}