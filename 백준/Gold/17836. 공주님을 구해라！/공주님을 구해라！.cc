#include<iostream>
#include<queue>
#include<tuple>
#include<cmath>
using namespace std;
#define MAX 100

bool visited[MAX][MAX];
int maze[MAX][MAX];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool success = false;
	
	int n, m, t;
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> maze[i][j];
	queue<tuple<int, int, int>>q;
	int answer = 1000000000;
	visited[0][0] = true;
	q.push(make_tuple(0, 0, 0));
	while (!q.empty()) {
		int r = get<0>(q.front());
		int c = get<1>(q.front());
		int cnt = get<2>(q.front());
		for (int i = 0; i < 4; i++) {
			if (r + dr[i] >= 0 && r + dr[i] < n && c + dc[i] >= 0 && c + dc[i] < m && !visited[r + dr[i]][c + dc[i]] && (maze[r + dr[i]][c + dc[i]] == 0 || maze[r + dr[i]][c + dc[i]] == 2)) {
				if (maze[r + dr[i]][c + dc[i]] == 2||(r+dr[i]==n-1&&c+dc[i]==m-1)) {
					answer = min(cnt + 1 + n - 1 - (r + dr[i]) + m - 1 - (c + dc[i]), answer);
					if (answer > t) {
						break;
					}
					success = true;
					break;
				}
				else {
					if (cnt + 1 > t)
						break;
					visited[r + dr[i]][c + dc[i]] = true;
					q.push(make_tuple(r + dr[i], c + dc[i], cnt + 1));
				}
			}
		}
		q.pop();
	}
	if (success)
		cout << answer << "\n";
	else
		cout << "Fail\n";
}