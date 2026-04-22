#include<iostream>
#include<queue>
#include<utility>

using namespace std;

#define SZ 50

bool arr[SZ][SZ];
bool visited[SZ][SZ];
int dr[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dc[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void bfs(int r, int c, int rs, int cs)
{
	visited[r][c] = true;
	queue<pair<int, int>>q;
	q.push(make_pair(r, c));
	while (!q.empty()) {
		int tmp_r = q.front().first;
		int tmp_c = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			if (tmp_r + dr[i] >= 0 && tmp_r + dr[i] < rs && tmp_c + dc[i] >= 0 && tmp_c + dc[i] < cs && arr[tmp_r + dr[i]][tmp_c + dc[i]] && !visited[tmp_r + dr[i]][tmp_c + dc[i]]) {
				visited[tmp_r + dr[i]][tmp_c + dc[i]] = true;
				q.push(make_pair(tmp_r + dr[i], tmp_c + dc[i]));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		int w, h;
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
				visited[i][j] = false;
			}
		}
		int land = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] && !visited[i][j]) {
					bfs(i, j, h, w);
					land++;
				}
			}
		}
		cout << land << "\n";
	}
}