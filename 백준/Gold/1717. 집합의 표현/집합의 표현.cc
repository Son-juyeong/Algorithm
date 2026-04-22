#include<iostream>
#define MAX 1000001

using namespace std;

int parent[MAX];
int node_rank[MAX];

int find(int x)
{
	if (x == parent[x])
		return x;
	else return parent[x] = find(parent[x]);
}

void union_set(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y) {
		if (node_rank[x] > node_rank[y]) parent[y] = x;
		else parent[x] = y;
		if (node_rank[x] == node_rank[y]) node_rank[y]++;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		parent[i] = i;
	for (int i = 0; i < m; i++) {
		int t, a, b;
		cin >> t >> a >> b;
		switch (t) {
		case 0:
			union_set(a, b);
			break;
		case 1:
			if (find(a) == find(b))
				cout << "yes\n";
			else
				cout << "no\n";
			break;
		}
	}
}