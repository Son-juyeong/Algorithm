#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

#define SZ 25

bool house[SZ][SZ] = { false };
bool visited[SZ][SZ] = { false };
queue<pair<int, int>> q;
int num_h[SZ*SZ] = { 0 };
int row_arr[4] = { -1, 1, 0, 0 };
int col_arr[4] = { 0, 0, -1, 1 };

void bfs(int r, int c, int o, int n) {
	visited[r][c] = true;
	num_h[o]++;
	q.push(make_pair(r, c));
	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (row + row_arr[i] >= 0 && row + row_arr[i] < n&& col + col_arr[i] >= 0 && col + col_arr[i] < n && !visited[row + row_arr[i]][col + col_arr[i]]&&house[row + row_arr[i]][col + col_arr[i]]) {
				visited[row + row_arr[i]][col + col_arr[i]] = true;
				q.push(make_pair(row + row_arr[i], col + col_arr[i]));
				num_h[o]++;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		cin.ignore(0);
		for (int j = 0; j < n; j++)
			house[i][j] = tmp[j] - '0';
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (house[i][j]&&!visited[i][j]) {
				bfs(i, j, cnt, n);
				cnt++;
			}
		}
	}
	sort(num_h, num_h + cnt);
	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++)
		cout << num_h[i] << "\n";
}