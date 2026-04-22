#include<iostream>
#include<queue>
#include<utility>

using namespace std;

#define MAX 1000

int n, m, r, c;
int arr[MAX][MAX];
int answer[MAX][MAX];
int dir_r[4] = { -1, 1, 0, 0 };
int dir_c[4] = { 0, 0, 1, -1 };

void bfs()
{
	queue<pair<int, int>> q;
	arr[r][c] = 0;
	q.push(make_pair(r, c));
	while (!q.empty()) {
		int tmp1 = q.front().first;
		int tmp2 = q.front().second;
		for (int i = 0; i < 4; i++) {
			if (tmp1 + dir_r[i] >= 0 && tmp1 + dir_r[i] < n && tmp2 + dir_c[i] >= 0 && tmp2 + dir_c[i] < m && arr[tmp1 + dir_r[i]][tmp2 + dir_c[i]]==1) {
				arr[tmp1 + dir_r[i]][tmp2 + dir_c[i]] = 0;
				answer[tmp1 + dir_r[i]][tmp2 + dir_c[i]] = answer[tmp1][tmp2] + 1;
				q.push(make_pair(tmp1 + dir_r[i], tmp2 + dir_c[i]));
			}
		}
		q.pop();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				r = i;
				c = j;
			}
		}
	}
	bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (arr[i][j] == 1)
				cout << -1 << " ";
			else
				cout << answer[i][j] << " ";
		cout << "\n";
	}
}