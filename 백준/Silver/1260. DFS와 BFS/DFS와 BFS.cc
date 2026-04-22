#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX 1001

vector<int> g[MAX];
bool visited[MAX] = { 0 };
int queue[MAX];
int front = -1, rear = -1;

void dfs(int a) {
	for(int i=0;i<g[a].size();i++)
		if (!visited[g[a][i]]) {
			cout << g[a][i] << " ";
			visited[g[a][i]] = true;
			dfs(g[a][i]);
		}
}

void bfs(int a) {
	visited[a] = true;
	queue[++rear] = a;
	cout << a << " ";
	while (front != rear) {
		++front;
		for (int i = 0; i < g[queue[front]].size(); i++) {
			if (!visited[g[queue[front]][i]]) {
				visited[g[queue[front]][i]] = true;
				queue[++rear] = g[queue[front]][i];
				cout << queue[rear] << " ";
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, v;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 1; i <=n; i++) {
		if (!g[i].empty())
			sort(g[i].begin(), g[i].end());
	}
	visited[v] = true;
	cout << v << " ";
	dfs(v);
	for (int i = 1; i <=n; i++)
		visited[i] = false;
	cout << "\n";
	bfs(v);
	cout << "\n";
}