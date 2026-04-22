#include<iostream>
#include<vector>

using namespace std;
vector<int> g[1001];
int v[1001] = { 0 };

void dfs(int a) {
	for (int i = 0; i < g[a].size(); i++) {
		if (v[g[a][i]] == 0) {
			v[g[a][i]] = 1;
			dfs(g[a][i]);
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int j, k;
		cin >> j >> k;
		g[j].push_back(k);
		g[k].push_back(j);
	}
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		if (v[i] == 0)
			cnt++;
		dfs(i);
	}
	
	cout << cnt << endl;
}