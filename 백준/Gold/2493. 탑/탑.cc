#include<iostream>

using namespace std;

#define MAX 500001

int arr[MAX][2] = { {0,0} };

int top(int n, int a) {
	if (arr[n][0] < a) {
		if (!arr[n][1])
			return 0;
		else
			return top(arr[n][1], a);
	}
	else
		return n;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0];
		arr[i][1] = top(i - 1, arr[i][0]);
		cout << arr[i][1] << " ";
	}
}