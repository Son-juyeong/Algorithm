#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int main()
{
	vector<pair<int, int>> timeschedule;
	pair<int, int> tmp;
	int n;
	cin >> n;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		timeschedule.push_back(make_pair(b, a));
	}
	sort(timeschedule.begin(), timeschedule.end());

	tmp = make_pair(timeschedule[0].first, timeschedule[0].second);
	for (int i = 1; i < n; i++) {
		if (timeschedule[i].second >= tmp.first) {
			tmp.first = timeschedule[i].first;
			tmp.second = timeschedule[i].second;
			cnt++;
		}
	}
	cout << cnt << endl;
}