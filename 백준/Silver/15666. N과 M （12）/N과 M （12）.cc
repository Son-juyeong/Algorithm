#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
int arr[9];
vector<int> num;
bool visited[9];

void dfs(int a, int phase) {
	if (phase == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = a; i < num.size(); i++) {
		arr[phase] = num[i];
		dfs(i, phase + 1);
		}
}

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}
		
	sort(num.begin(), num.end());
	num.erase(unique(num.begin(), num.end()), num.end());
	dfs(0, 0);
}