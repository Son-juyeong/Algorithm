#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int w[50001];
int const INF = 50000001;
vector <vector<pair<int, int>> > v;

struct cmp {
	bool operator()(pair<int, int>a, pair<int, int>b) {
		return a.second > b.second;
	}
};

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		w[i] = INF;
		vector<pair<int, int>> t;
		v.push_back(t);
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

	int answer = 0;

	pq.push(make_pair(1, 0));
	while (!pq.empty()) {
		pair<int, int> p = pq.top();
		int node = p.first;
		int weight = p.second;
		if (node == n) {
			answer = weight;
			break;
		}
		pq.pop();
		for (int i = 0; i < v[node].size(); i++) {
			pair<int, int> temp = v[node][i];
			if (w[temp.first] > weight + temp.second) {
				w[temp.first] = weight + temp.second;
				pq.push(make_pair(temp.first, weight + temp.second));
			}
		}
	}
	cout << answer;
	return 0;
}