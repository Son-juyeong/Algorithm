#include<iostream>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<long long> c;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		long long t;
		cin >> t;
		c.push_back(t);
	}
	long long max_num = 0;
	for (int i = 0; i < m; i++) {
		max_num += c[i];
	}
	long long tmp = max_num;
	for (int i = m; i < n; i++) {
		tmp += c[i] - c[i - m];
		max_num = max(tmp, max_num);
	}

	cout << max_num << endl;
}