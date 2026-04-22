#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int person = 1;
		vector<pair<int, int>> rank;
		for (int j = 0; j < n; j++) {
			int a, b;
			cin >> a >> b;
			rank.push_back(make_pair(a, b));
		}
		sort(rank.begin(), rank.end());
		int tmp = rank[0].second;
		for (int j = 1; j < n; j++) {
			if (tmp > rank[j].second) {
				person++;
				tmp = rank[j].second;
			}
		}
		cout << person << endl;
	}
}