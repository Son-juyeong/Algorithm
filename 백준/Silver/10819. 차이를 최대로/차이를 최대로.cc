#include<iostream>
using namespace std;

int arr[8];
int answer_arr[8];
int answer;
int n;
bool visited[8];

void dfs(int cnt)
{
	if (cnt == n) {
		int sum = 0;
		for (int i = 0; i < n-1; i++) {
			sum += abs(answer_arr[i]-answer_arr[i+1]);
		}
		answer = max(answer, sum);
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				visited[i] = true;
				answer_arr[cnt] = arr[i];
				dfs(cnt + 1);
				visited[i] = false;
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dfs(0);
	cout << answer << endl;
}