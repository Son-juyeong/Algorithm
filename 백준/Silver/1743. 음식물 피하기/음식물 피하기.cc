#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>

using namespace std;

bool graph[101][101];
bool visited[101][101];
int row[] = { -1, 0, 1, 0 };
int col[] = { 0, 1, 0, -1 };

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		graph[r][c] = true;
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (graph[i][j] && !visited[i][j]) {
				int temp = 1;
				queue <pair<int, int>> q;
				q.push(make_pair(i, j));
				visited[i][j] = true;
				while (!q.empty()) {
					pair<int, int> p = q.front();
					q.pop();
					for (int k = 0; k < 4; k++) {
						int r = p.first + row[k];
						int c = p.second + col[k];
						if (r > 0 && r <= n && c > 0 && c <= m && graph[r][c] && !visited[r][c]) {
							temp++;
							visited[r][c] = true;
							q.push(make_pair(r, c));
						}
					}
				}
				answer = max(answer, temp);
			}
		}
	}
	cout << answer;
	return 0;
}