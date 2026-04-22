#include<iostream>
#include<utility>
#include<queue>

using namespace std;

#define SZ 100

bool p1[SZ][SZ];
bool p2[SZ][SZ];
char color[SZ][SZ];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void bfs_p1(int r, int c, char w, int n) {
	p1[r][c] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	while (!q.empty()) {
		int rtmp = q.front().first;
		int ctmp = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (rtmp + dr[i] >= 0 && rtmp + dr[i] < n && ctmp + dc[i] >= 0 && ctmp + dc[i] < n && color[rtmp + dr[i]][ctmp + dc[i]] == w && !p1[rtmp + dr[i]][ctmp + dc[i]]) {
				p1[rtmp + dr[i]][ctmp + dc[i]] = true;
				q.push(make_pair(rtmp + dr[i], ctmp + dc[i]));
			}
		}
	}
}
void bfs_p2(int r, int c, int n) {
	p2[r][c] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	while (!q.empty()) {
		int rtmp = q.front().first;
		int ctmp = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (rtmp + dr[i] >= 0 && rtmp + dr[i] < n && ctmp + dc[i] >= 0 && ctmp + dc[i] < n && (color[rtmp + dr[i]][ctmp + dc[i]] == 'R' || color[rtmp + dr[i]][ctmp + dc[i]] == 'G') && !p2[rtmp + dr[i]][ctmp + dc[i]]) {
				p2[rtmp + dr[i]][ctmp + dc[i]] = true;
				q.push(make_pair(rtmp + dr[i], ctmp + dc[i]));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, rg1 = 0, b = 0, rg2 = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> color[i][j];
		cin.ignore();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!p1[i][j]) {
				bfs_p1(i, j, color[i][j], n);
				if (color[i][j] == 'R' || color[i][j] == 'G')
					rg1++;
				else if (color[i][j] == 'B')
					b++;
			}
			if (!p2[i][j] && (color[i][j] == 'R' || color[i][j] == 'G')) {
				bfs_p2(i, j, n);
				rg2++;
			}
		}
	}
	cout << rg1 + b << " " << rg2 + b << endl;
}