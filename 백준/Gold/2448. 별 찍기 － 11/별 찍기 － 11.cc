#include<iostream>

using namespace std;

#define SZ 3072

char arr[SZ][2*SZ];

void star(int a, int b, int n) {
	if (n == 3) {
		arr[a][b] = arr[a + 1][b - 1] = arr[a + 1][b + 1] = arr[a + 2][b - 2] = arr[a + 2][b - 1] = arr[a + 2][b] = arr[a + 2][b + 1] = arr[a + 2][b + 2] = '*';
	}
	else {
		star(a, b, n / 2);
		star(a + n / 2, b - n / 2, n / 2);
		star(a + n / 2, b + n / 2, n / 2);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2*n-1; j++)
			arr[i][j] = ' ';

	star(0, n-1, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2*n-1; j++)
			cout << arr[i][j];
		cout << "\n";
	}
}