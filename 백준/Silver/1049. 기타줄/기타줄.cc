#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> p6;
	vector<int> p1;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		p6.push_back(t1);
		p1.push_back(t2);
	}

	sort(p6.begin(), p6.end());
	sort(p1.begin(), p1.end());

	int t1, t2, t3;
	t1 = (n / 6 + 1) * p6[0];
	t2 = n / 6 * p6[0] + n % 6 * p1[0];
	t3 = n * p1[0];

	int mp = min({ t1, t2, t3 });

	cout << mp << endl;

}