#include<iostream>

using namespace std;

#define SZ 2188
int arr[SZ][SZ];
int minus_one = 0, zero = 0, one = 0;

void func(int r, int c, int n) {
	bool same = true;
	int tmp = arr[r][c];
	for (int i = r; i < n+r; i++) {
		for (int j = c; j < n+c; j++)
			if (arr[i][j] != tmp) {
				same = false;
				break;
			}
		if (!same)
			break;
	}
	if (!same) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				func(r + n / 3 * i, c + n / 3 * j, n / 3);
	}
	else {
		if (tmp == -1)
			minus_one++;
		else if (tmp == 0)
			zero++;
		else
			one++;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	
	func(1, 1, n);

	cout << minus_one << endl;
	cout << zero << endl;
	cout << one << endl;
}