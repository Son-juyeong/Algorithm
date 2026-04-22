#include<iostream>
#include<queue>
#include<utility>
#include<set>

#define MAX 50

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		bool visited[MAX][MAX] = { 0 };
		set<pair<int, int>> veg;
		queue<pair<int, int>> p;
		int cnt = 0;
		int m, n, k;
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++) {
			int tmp1, tmp2;
			cin >> tmp2 >> tmp1;
			veg.insert(make_pair(tmp1, tmp2));
		}
		for (auto iter = veg.begin(); iter != veg.end();iter++) {
			if (!visited[(*iter).first][(*iter).second]) {
				visited[(*iter).first][(*iter).second] = true;
				p.push(make_pair((*iter).first, (*iter).second));
				while (!p.empty()) {
					int r = p.front().first;
					int c = p.front().second;
					p.pop();
					if (veg.find({ r + 1, c }) != veg.end() && !visited[r + 1][c]) {
						visited[r + 1][c] = true;
						p.push(make_pair(r + 1, c));
					}
					if (veg.find({ r - 1, c }) != veg.end() && !visited[r - 1][c]) {
						visited[r - 1][c] = true;
						p.push(make_pair(r - 1, c));
					}
					if (veg.find({ r, c+1 }) != veg.end() && !visited[r][c+1]) {
						visited[r][c+1] = true;
						p.push(make_pair(r, c+1));
					}
					if (veg.find({ r, c-1 }) != veg.end() && !visited[r][c-1]) {
						visited[r][c-1] = true;
						p.push(make_pair(r, c-1));
					}
				}
				cnt++;
			}
		}
		cout << cnt << "\n";
	}


}