#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int N, M, K;
int visited[1000][1000];
char arr[1000][1000];

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

struct Node {
	int r;
	int c;
	int d;
	int cnt;
	Node(int r, int c, int d, int cnt) : r(r), c(c), d(d), cnt(cnt){}
};

int BFS() {

	if (N == 1 && M == 1) return 1;

	queue<Node> q;
	q.push(Node(0, 0, 1, 0));
	while (!q.empty()) {
		Node cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int r = cur.r + dr[i];
			int c = cur.c + dc[i];
			if (r >= 0 && r < N && c >= 0 && c < M) {
				if (r == N - 1 && c == M - 1)
					return cur.d + 1;
				if (arr[r][c] == '0') {
					if ((visited[r][c] & (1<<cur.cnt)) == 0) {
						visited[r][c] |= (1 << cur.cnt);
						q.push(Node(r, c, cur.d + 1, cur.cnt));
					}
				}
				else {
					if (cur.cnt < K && ((visited[r][c] & (1 << (cur.cnt + 1))) == 0)) {
						visited[r][c] |= (1 << (cur.cnt + 1));
						q.push(Node(r, c, cur.d + 1, cur.cnt + 1));
					}
				}
			}
		}

	}
	return -1;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	cout << BFS();

	return 0;
}