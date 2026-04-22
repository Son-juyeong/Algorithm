#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

bool cmp(int a, int b) {
	if (abs(a) == abs(b))
		return a < b;
	else
		return abs(a) < abs(b);
}

vector<int> v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int m = 2000000001;
	int a, b;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n - 1; i++) {
		int tmp = abs(v[i] + v[i + 1]);
		if (tmp < m) {
			a = v[i];
			b = v[i + 1];
			m = tmp;
		}
	}
	cout << min(a, b) << " " << max(a, b) << endl;
}