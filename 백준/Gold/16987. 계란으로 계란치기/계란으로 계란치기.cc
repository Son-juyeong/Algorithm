#include<iostream>
#include<cmath>

using namespace std;

int egg[2][8];
int n;
int answer;

void dfs(int depth, int cnt) {
	if (depth == n) {
		answer = max(answer, cnt);
		return;
	}
	if (egg[0][depth] <= 0) {
		dfs(depth + 1, cnt);
		return;
	}
	bool b = true;
	for (int i = 0; i < n; i++) {
		if (egg[0][i] <= 0||i==depth) continue;
		b = false;
		int temp_cnt = cnt;
		egg[0][depth] -= egg[1][i];
		egg[0][i] -= egg[1][depth];
		if (egg[0][depth] <= 0) temp_cnt++;
		if (egg[0][i] <= 0) temp_cnt++;
		dfs(depth + 1, temp_cnt);
		egg[0][depth] += egg[1][i];
		egg[0][i] += egg[1][depth];
	}
	if (b) {
		answer = max(answer, cnt);
		return;
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, w;
		cin >> s >> w;
		egg[0][i] = s;
		egg[1][i] = w;
	}
	dfs(0, 0);
	cout << answer;
}