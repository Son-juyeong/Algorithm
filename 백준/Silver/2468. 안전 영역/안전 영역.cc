#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
#define SZ 100

using namespace std;

int n, answer = 1;
int arr[SZ][SZ];
bool visited[SZ][SZ];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void bfs(int a, int b, int depth) {
	visited[a][b] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		for (int i = 0; i < 4; i++) {
			if (r + dr[i] >= 0 && r + dr[i] < n && c + dc[i] >= 0 && c + dc[i]<n && arr[r + dr[i]][c + dc[i]]>depth && !visited[r + dr[i]][c + dc[i]]) {
				visited[r + dr[i]][c + dc[i]] = true;
				q.push(make_pair(r + dr[i], c + dc[i]));
			}
		}
		q.pop();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	for (int i = 1; i <= 100; i++) {
		int tmp = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (arr[j][k] > i && !visited[j][k]) {
					bfs(j, k, i);
					tmp++;
				}
			}
		}
		answer = max(answer, tmp);
		if (i == 100) break;
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				visited[j][k] = false;
	}
	cout << answer << endl;
}