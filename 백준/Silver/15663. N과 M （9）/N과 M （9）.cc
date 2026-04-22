#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int arr[9];
int num[9];
bool visited[9];

void dfs(int phase) {
	if (phase == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			if (i > 0 && num[i] == num[i - 1] && !visited[i - 1]) {
				visited[i] = false;
				continue;
			}
			arr[phase] = num[i];
			dfs(phase + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort(num, num + n);
	dfs(0);
}