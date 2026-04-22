#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool v[101] = { 0 };
vector<int> graph[101];

void dfs(int a, int* b) {
	for (int i = 0; i < graph[a].size(); i++) {
		if (!v[graph[a][i]]) {
			v[graph[a][i]] = true;
			(*b)++;
			dfs(graph[a][i], b);
		}
	}
}

int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int max_num = 0;

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		if (!v[i]) {
			v[i] = true;
			dfs(i, &cnt);
		}
		max_num = max(cnt, max_num);
	}

	cout << max_num << endl;
}