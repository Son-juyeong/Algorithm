#include<iostream>
#include<vector>

using namespace std;

#define MAX 10001

vector<int> com[MAX];
bool visited[MAX] = { 0 };

void dfs(int a, int *n) {
	for (int i = 0; i < com[a].size(); i++) {
		if (!visited[com[a][i]]) {
			visited[com[a][i]] = true;
			(*n)++;
			dfs(com[a][i], n);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		com[b].push_back(a);
	}
	int max_num = 0;
	vector<int> com_num;
	for (int i = 1; i <= n; i++) {
		int cnt = 1;
		visited[i] = true;
		dfs(i, &cnt);
		if (max_num < cnt) {
			com_num.clear();
			com_num.push_back(i);
			max_num = cnt;
		}
		else if (max_num == cnt)
			com_num.push_back(i);
		for (int j = 1; j <= n; j++)
			visited[j] = false;
	}
	for (int i = 0; i < com_num.size(); i++)
		cout << com_num[i] << " ";
}