#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define SZ 50

using namespace std;

int arr[SZ][SZ];
bool visited[SZ][SZ];
int n, L, R;
int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { 1, 0, -1, 0 };

void bfs(int r, int c, bool* b)
{
	int p = 0;
	vector<pair<int, int>> v;
	v.push_back(make_pair(r, c));
	visited[r][c] = true;
	int total = arr[r][c];
	while (v.size() > p) {
		int tr = v[p].first;
		int tc = v[p].second;
		for (int i = 0; i < 4; i++) {
			if (tr + dr[i] >= 0 && tr + dr[i] < n && tc + dc[i] >= 0 && tc + dc[i] < n && !visited[tr + dr[i]][tc + dc[i]] && abs(arr[tr][tc] - arr[tr + dr[i]][tc + dc[i]]) >= L && abs(arr[tr][tc] - arr[tr + dr[i]][tc + dc[i]]) <= R) {
				visited[tr + dr[i]][tc + dc[i]] = true;
				total += arr[tr + dr[i]][tc + dc[i]];
				v.push_back(make_pair(tr + dr[i], tc + dc[i]));
				if (!(*b)) *b = true;
			}
		}
		p++;
	}
	total /= v.size();
	for (int i = 0; i < v.size(); i++)
		arr[v[i].first][v[i].second] = total;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> L >> R;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}
	int answer = 0;
	while (true)
	{
		bool act = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				visited[i][j] = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) bfs(i, j, &act);
			}
		}
		if (!act) break;
		else answer++;
	}
	cout << answer << endl;
}