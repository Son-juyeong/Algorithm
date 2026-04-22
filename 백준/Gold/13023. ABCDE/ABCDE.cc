#include<iostream>
#include<vector>

using namespace std;

bool f = false;
vector<int> v[2000];
int cnt;

void dfs(bool* a, int num) {
	if (cnt == 5) {
		f = true;
		return;
	}
	else {
		if (f)
			return;
		a[num] = true;
		for(int i=0;i<v[num].size();i++)
			if (!a[v[num][i]]) {
				a[v[num][i]] = true;
				cnt++;
				dfs(a, v[num][i]);
			}
		cnt--;
		a[num] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool friends = false;
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		bool visited[2000] = { false };
		cnt = 1;
		dfs(visited, i);
		if (f)
			break;
	}
	if (f)
		cout << 1 << endl;
	else
		cout << 0 << endl;
}