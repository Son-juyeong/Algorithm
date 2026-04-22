#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#define MAX 10000

using namespace std;

string visited[MAX];

void bfs(int start, int end)
{
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		if ((tmp * 2) % MAX != start && visited[(tmp * 2) % MAX] == "\0") {
			visited[(tmp * 2) % MAX] += visited[tmp];
			visited[(tmp * 2) % MAX] += "D";
			if ((tmp * 2) % MAX == end) { cout << visited[(tmp * 2) % MAX] << "\n"; break; }
			q.push((tmp * 2) % MAX);
		}
		if ((tmp == 0 && 9999 != start && visited[9999] == "\0") || (tmp!=0&&tmp - 1 != start && visited[tmp - 1] == "\0")) {
			if (tmp == 0) {
				visited[9999] += visited[tmp];
				visited[9999] += "S";
				if (9999 == end) { cout << visited[9999] << "\n"; break; }
				q.push(9999);
			}
			else {
				visited[tmp - 1] += visited[tmp];
				visited[tmp - 1] += "S";
				if (tmp - 1 == end) { cout << visited[tmp - 1] << "\n"; break; }
				q.push(tmp - 1);
			}
		}
		if ((tmp / 1000) + ((tmp % 1000) * 10) != start && visited[(tmp / 1000) + ((tmp % 1000) * 10)] == "\0") {
			visited[(tmp / 1000) + ((tmp % 1000) * 10)] += visited[tmp];
			visited[(tmp / 1000) + ((tmp % 1000) * 10)] += "L";
			if ((tmp / 1000) + ((tmp % 1000) * 10) == end) { cout << visited[(tmp / 1000) + ((tmp % 1000) * 10)] << "\n"; break; }
			q.push((tmp / 1000) + ((tmp % 1000) * 10));
		}
		if ((tmp % 10) * 1000 + tmp / 10 != start && visited[(tmp % 10) * 1000 + tmp / 10] == "\0") {
			visited[(tmp % 10) * 1000 + tmp / 10] += visited[tmp];
			visited[(tmp % 10) * 1000 + tmp / 10] += "R";
			if ((tmp % 10) * 1000 + tmp / 10 == end) { cout << visited[(tmp % 10) * 1000 + tmp / 10] << "\n"; break; }
			q.push((tmp % 10) * 1000 + tmp / 10);
		}
	}
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < MAX; j++)
			visited[j].clear();
		int a, b;
		cin >> a >> b;
		bfs(a, b);
	}
}