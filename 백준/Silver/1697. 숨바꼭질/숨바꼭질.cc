#include<iostream>
#include<queue>

using namespace std;

#define MAX 100001

bool visited[MAX] = { false };
int t[MAX] = { 0 };

queue<int> p;

void bfs(int a, int b) {
	visited[a] = true;
	p.push(a);
	while (!p.empty()) {
		int tmp = p.front();
		p.pop();
		if (tmp*2<=100000&&!visited[tmp * 2]) {
			t[tmp * 2] = t[tmp] + 1;
			if (tmp * 2 == b)
				break;
			visited[tmp * 2] = true;
			p.push(tmp * 2);
		}
		if (tmp+1<=100000&&!visited[tmp + 1]) {
			t[tmp + 1] = t[tmp] + 1;
			if (tmp + 1 == b)
				break;
			visited[tmp + 1] = true;
			p.push(tmp + 1);
		}
		if (tmp-1>=0&&!visited[tmp - 1]) {
			t[tmp - 1] = t[tmp] + 1;
			if (tmp - 1 == b)
				break;
			visited[tmp - 1] = true;
			p.push(tmp - 1);
		}
	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	bfs(n, k);
	cout << t[k] << endl;
}