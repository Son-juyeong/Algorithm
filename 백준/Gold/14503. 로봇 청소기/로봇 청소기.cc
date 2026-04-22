#include<iostream>

using namespace std;

#define SZ 50

bool room[SZ][SZ];
bool p[SZ][SZ];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

void clean(int r, int c, int n, int m, int d, int* cnt) {
	bool nc = false;
	if (!room[r][c]) {
		room[r][c] = true;
		(*cnt)++;
	}
	int j;
	for (int i = 3; i >= 0; i--) {
		j = (i + d) % 4;
		if (r + dr[j] >= 1 && r + dr[j] < n-1 && c + dc[j] >= 1 && c + dc[j] < m-1 && !room[r + dr[j]][c + dc[j]]) {
			nc = true;
			break;
		}
	}
	if (nc) {
		clean(r + dr[j], c + dc[j], n, m, j, cnt);
	}
	else {
		int t = (2 + d) % 4;
		if (r + dr[t] >= 1 && r + dr[t] < n-1 && c + dc[t] >= 1 && c + dc[t] < m-1&&p[r+dr[t]][c+dc[t]])
			clean(r + dr[t], c + dc[t], n, m, d, cnt);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int cnt = 0;
	int n, m, r, c, d;
	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
			p[i][j] = !room[i][j];
		}
	}

	clean(r, c, n, m, d, &cnt);
	
	cout << cnt << endl;
}