#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

queue<int> q[1001];
int arr[50];
int sorted_arr[50];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		arr[i] = sorted_arr[i]=t;
	}

	sort(sorted_arr, sorted_arr + n);

	for (int i = 0; i < n; i++) {
		q[sorted_arr[i]].push(i);
	}

	for (int i = 0; i < n; i++) {
		int t = q[arr[i]].front();
		q[arr[i]].pop();
		cout << t << " ";
	}

	return 0;
}