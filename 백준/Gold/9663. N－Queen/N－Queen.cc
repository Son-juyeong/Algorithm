#include<iostream>
#include<cmath>

using namespace std;

int n, answer;
bool col[15];
int arr[15];

void dfs(int depth) {
	if (depth == n) answer++;
	for (int i = 0; i < n; i++) {
		if (col[i]) continue;
		bool b = false;
		for (int j = 0; j < depth; j++) {
			if (depth - j == abs(i - arr[j])) {
				b = true; break;
			}
		}
		if (b) continue;
		col[i] = true;
		arr[depth] = i;
		dfs(depth + 1);
		col[i] = false;
	}
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	dfs(0);
	cout << answer;
}