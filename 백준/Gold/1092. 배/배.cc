#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;


int main() {
	vector<pair<int, int>> box;
	vector<int>crane;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		crane.push_back(t);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		box.push_back({t, 0});
	}

	sort(crane.begin(), crane.end());
	sort(box.begin(), box.end());

	bool trying = true;
	int cnt = 0;
	while (1) {
		if (box.size() == 0)
			break;
		int p = box.size() - 1;
		int j = p;
		int t = n - 1;
		if (crane[t] < box[p].first) {
			trying = false;
			break;
		}
		while (t>=0&&p>=0) {
			if (crane[t] >= box[p].first && box[p].second == 0) {
				box[p].second = 1;
				t--;
			}
			p--;
		}
		while (box[j].second) {
			box.pop_back();
			if (j == 0)
				break;
			j--;
		}
		cnt++;
	}
	if (trying)
		cout << cnt;
	else
		cout << -1;
}
