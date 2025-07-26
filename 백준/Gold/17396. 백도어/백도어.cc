#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

bool sight[100000];
long long w[100000];
vector < vector<pair<int, long long>>> v;

long long const INF = 40000000001;

struct cmp {
	bool operator()(pair<int, long long> a, pair<int, long long> b) {
		return a.second > b.second;
	}
};

priority_queue<pair<int, long long>, vector<pair<int, long long>>, cmp> pq;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		sight[i] = s;
		vector<pair<int, long long>> t;
		v.push_back(t);
		w[i] = INF;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}

	//long long answer = -1;

	pq.push(make_pair(0, 0));
	while (!pq.empty()) {
		pair<int, long long> p = pq.top();
		pq.pop();
		int node = p.first;
		long long weight = p.second;
		/*if (node == n - 1) {
			answer = weight;
			break;
		}*/
		if (w[node] < weight)
			continue;
		for (int i = 0; i < v[node].size(); i++) {
			int next_node = v[node][i].first;
			long long new_weight = weight + v[node][i].second;
			if ((next_node == n - 1||!sight[next_node]) && w[next_node]>new_weight) {
				w[next_node] = new_weight;
				pq.push(make_pair(next_node, new_weight));
			}
		}
	}

	long long answer = w[n - 1] == INF ? -1 : w[n - 1];

	cout << answer<<"\n";
	return 0;
}