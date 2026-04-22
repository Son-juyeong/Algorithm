#include<iostream>
#include<queue>
#include<vector>
#include<utility>

using namespace std;

#define SZ 1000

int graph[SZ][SZ];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int days = 0;
int m, n;
vector<pair<int, int>> one_p;
queue<pair<int, int>> q[2];

void bfs(int* c) {
	for (int i = 0; i < one_p.size(); i++)
		q[days].push(make_pair(one_p[i].first, one_p[i].second));
	int day = 0;
	while (!q[day].empty()) {
		while (!q[day].empty()) {
			int row = q[day].front().first;
			int col = q[day].front().second;
			q[day].pop();
			for (int i = 0; i < 4; i++) {
				if (row + dr[i] >= 0 && row + dr[i] < n && col + dc[i] >= 0 && col + dc[i] < m && graph[row + dr[i]][col + dc[i]] == 0) {
					graph[row + dr[i]][col + dc[i]] = 1;
					q[(day + 1)%2].push(make_pair(row + dr[i], col + dc[i]));
					(*c)++;
				}
			}
		}
		days++;
		day = (day + 1) % 2;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int one = 0, m_one = 0;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1) {
				one_p.push_back(make_pair(i, j));
				one++;
			}
			else if (graph[i][j] == -1)
				m_one++;
		}
	}
	if (one + m_one == m * n)
		cout << 0 << "\n";
	else {
		int tmp_one = one;
		bfs(&tmp_one);
		if (tmp_one + m_one == m * n)
			cout << days-1 << "\n";
		else
			cout << -1 << "\n";
	}
}