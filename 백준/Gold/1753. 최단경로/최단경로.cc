#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int const INF = 3000001;
vector < pair<int, int>> graph[20001];

struct cmp {
	bool operator()(pair<int, int>a, pair<int, int> b) {
		return a.second > b.second;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
int dist[20001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int V, E, K;
	cin >> V >> E >> K;

	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
		//graph[v].push_back(make_pair(u, w));
	}

	pq.push(make_pair(K, 0));
	dist[K] = 0;

	while (!pq.empty()) {
		pair<int, int> p = pq.top();
		pq.pop();
		int node = p.first;
		int dt = p.second;
		if (dist[node] < dt)
			continue;
		for (int i = 0; i < graph[node].size(); i++) {
			pair<int, int> tp = graph[node][i];
			if (dist[tp.first] > dt+tp.second) {
				dist[tp.first] = dt + tp.second;
				pq.push(make_pair(tp.first, tp.second + dt));
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}


	return 0;
}