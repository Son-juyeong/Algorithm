#include<iostream>
#include<queue>
#include<algorithm>
#define SZ 101
using namespace std;

int ladder[SZ];
int snake[SZ];
bool visited[SZ] = { true, true };

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		ladder[t1] = t2;
	}
	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		snake[t1] = t2;
	}
	bool stop = false;
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	while (!q.empty()&&!stop) {
		int p = q.front().first;
		int cnt = q.front().second;
		for (int i = 1; i <= 6; i++) {
			if (p + i <= 100 && !visited[p + i]) {
				if (ladder[p + i] != 0) {
					if (ladder[p + i] == 100) {
						cout << cnt + 1 << endl;
						stop = true;
						break;
					}
					q.push(make_pair(ladder[p + i], cnt + 1));
					visited[ladder[p + i]] = true;
				}
				else if (snake[p + i] != 0) {
					q.push(make_pair(snake[p + i], cnt + 1));
					visited[snake[p + i]] = true;
				}
				else {
					if (p+i == 100) {
						cout << cnt + 1 << endl;
						stop = true;
						break;
					}
					q.push(make_pair(p + i, cnt + 1));
					visited[p + i] = true;
				}
			}
		}
		q.pop();
	}
}