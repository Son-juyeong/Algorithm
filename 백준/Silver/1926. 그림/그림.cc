#include<iostream>
#include<queue>
#include<utility>
#include<cmath>
#define MAX 500
using namespace std;

int n, m;
bool arr[MAX][MAX];
bool visited[MAX][MAX];
int cnt, area;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

int bfs(int r, int c)
{
	int answer = 1;
	visited[r][c] = true;
	queue<pair<int, int>>q;
	q.push(make_pair(r, c));
	while (!q.empty()) {
		int t1 = q.front().first;
		int t2 = q.front().second;
		for(int i=0;i<4;i++)
			if (t1 + dr[i] >= 0 && t1 + dr[i] < n && t2 + dc[i] >= 0 && t2 + dc[i] < m && !visited[t1 + dr[i]][t2 + dc[i]] && arr[t1 + dr[i]][t2 + dc[i]]) {
				visited[t1 + dr[i]][t2 + dc[i]] = true;
				answer++;
				q.push(make_pair(t1 + dr[i], t2 + dc[i]));
			}
		q.pop();
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] && !visited[i][j]) {
				cnt++;
				area = max(area, bfs(i, j));
			}
		}
	}
	cout << cnt << "\n" << area << "\n";
}