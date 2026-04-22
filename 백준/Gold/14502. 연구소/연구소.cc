#include<iostream>
#include<algorithm>
#include<queue>
#define SZ 8

using namespace std;

bool visited[SZ][SZ];
int arr[SZ][SZ];
int n, m;
int answer;
int r[4] = { 0, 1, 0, -1 };
int c[4] = { 1, 0, -1, 0 };

void dfs(int row, int col, int dept)
{
	if (dept == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && arr[i][j] == 2) {
					queue<pair<int, int>>q;
					visited[i][j] = true;
					q.push(make_pair(i, j));
					while (!q.empty()) {
						int tr = q.front().first;
						int tc = q.front().second;
						for (int i = 0; i < 4; i++) {
							int cr = tr + r[i];
							int cc = tc + c[i];
							if (cr >= 0 && cr < n && cc >= 0 && cc < m && !visited[cr][cc] && (arr[cr][cc] == 0 || arr[cr][cc] == 2)) {
								visited[cr][cc] = true;
								q.push(make_pair(cr, cc));
							}
						}
						q.pop();
					}
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!visited[i][j] && arr[i][j] == 0)
					cnt++;
		answer = max(answer, cnt);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if ((arr[i][j] == 2 || arr[i][j] == 0) && visited[i][j])
					visited[i][j] = false;
	}
	else {
		for (int i = row; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == row && j < col) continue;
				if (arr[i][j] == 0) {
					arr[i][j] = 1;
					dfs(i, j, dept + 1);
					arr[i][j] = 0;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	dfs(0, 0, 0);
	cout << answer << endl;
}