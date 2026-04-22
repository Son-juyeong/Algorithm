#include<iostream>

using namespace std;

int pre[100001] = { 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		pre[i] = t + pre[i - 1];
	}
	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		cout << pre[t2] - pre[t1 - 1] << "\n";
	}
}