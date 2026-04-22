#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int n, m;
int answer = 10000000;

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

void dfs(int order, int depth, vector<pair<int, int>> v)
{
	if (depth == m) {
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int dis = 10000000;
			for (int j = 0; j < v.size(); j++) {
				dis = min(dis, abs(house[i].first - v[j].first) + abs(house[i].second - v[j].second));
			}
			sum += dis;
		}
		answer = min(answer, sum);
	}
	else {
		for (int i = order; i < chicken.size(); i++) {
			v.push_back(make_pair(chicken[i].first, chicken[i].second));
			dfs(i + 1, depth + 1, v);
			v.pop_back();
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t;
			cin >> t;
			if (t == 1)
				house.push_back(make_pair(i, j));
			else if (t == 2)
				chicken.push_back(make_pair(i, j));
		}
	}
	vector<pair<int, int>> v;
	dfs(0, 0, v);
	cout << answer << endl;
}