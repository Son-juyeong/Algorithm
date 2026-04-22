#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int arr[9];
int num[9];
bool visited[9];

void dfs(int a, int phase) {
	if (phase == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = a; i < n; i++) {
			arr[phase] = num[i];
			dfs(i, phase + 1);
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
	dfs(0, 0);
}