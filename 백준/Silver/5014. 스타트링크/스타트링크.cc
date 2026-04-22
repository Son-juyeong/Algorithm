#include<iostream>
#include<queue>
#define SZ 1000001

using namespace std;

int bfs[SZ];

int main()
{
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	bool answer = false;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int tmp = q.front();
		if (tmp == g) {
			answer = true;
			cout << bfs[tmp] << endl;
			break;
		}
		if (u!=0&&tmp + u <= f && bfs[tmp + u] == 0&&tmp + u != s) {
			bfs[tmp + u] = bfs[tmp] + 1;
			q.push(tmp + u);
		}
		if (d != 0 && tmp - d > 0 &&bfs[tmp-d]==0 &&tmp - d != s) {
			bfs[tmp - d] = bfs[tmp] + 1;
			q.push(tmp - d);
		}
		q.pop();
	}
	if (!answer)
		cout << "use the stairs" << endl;
}