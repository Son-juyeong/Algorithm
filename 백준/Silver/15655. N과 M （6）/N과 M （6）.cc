#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
int combi[8];
int arr[8];

void dfs(int depth, int start) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << combi[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = start; i < N; i++) {
		combi[depth] = arr[i];
		dfs(depth + 1, i + 1);
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	dfs(0, 0);
	return 0;
}