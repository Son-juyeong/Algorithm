#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define SZ 300001

using namespace std;

bool visited[SZ];
vector<int> graph[SZ];
queue<pair<int, int>>q;
vector<int> answer;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, k, x;
	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		graph[t1].push_back(t2);
	}
	visited[x] = true;
	q.push(make_pair(x, 0));
	while (!q.empty()) {
		int n = q.front().first;
		int cnt = q.front().second;
		for (int i = 0; i < graph[n].size(); i++) {
			if (!visited[graph[n][i]]) {
				visited[graph[n][i]] = true;
				q.push(make_pair(graph[n][i], cnt + 1));
				if (cnt + 1 == k)
					answer.push_back(graph[n][i]);
			}
		}
		q.pop();
	}
	sort(answer.begin(), answer.end());
	if (answer.size() == 0)
		cout << -1 << endl;
	else
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << "\n";
		}
}