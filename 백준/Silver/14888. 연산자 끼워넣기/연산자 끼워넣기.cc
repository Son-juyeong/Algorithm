#include<iostream>
#include<cmath>

using namespace std;

int	operands[11];
int operators[4];
int n;

long long max_num = -1000000000;
long long min_num = 1000000000;

void dfs(int operands_idx, long long num)
{
	if (operands_idx == n) {
		max_num = max(max_num, num);
		min_num = min(min_num, num);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (operators[i] > 0) {
			long long temp = num;
			switch (i) {
			case 0:
				temp = num + (long long)operands[operands_idx];
				break;
			case 1:
				temp = num - (long long)operands[operands_idx];
				break;
			case 2:
				temp = num * (long long)operands[operands_idx];
				break;
			case 3:
				temp = num / (long long)operands[operands_idx];
				break;
			}
			operators[i]--;
			dfs(operands_idx + 1, temp);
			operators[i]++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> operands[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
	}
	dfs(1, operands[0]);
	cout << max_num << "\n";
	cout << min_num << "\n";
}