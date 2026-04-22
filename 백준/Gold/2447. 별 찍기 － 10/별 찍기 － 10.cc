#include<iostream>

using namespace std;

#define MAX 6561
char arr[MAX][MAX];

void star(int a, int b, int n) {
	if (n == 1) {
		arr[a][b] = '*';
	}
	else if(n>1) {
		star(a, b, n / 3);
		star(a, b + n / 3, n / 3);
		star(a, b + 2 * (n / 3), n / 3);
		star(a+n/3, b, n / 3);
		star(a+n/3, b + 2 * (n / 3), n / 3);
		star(a + 2 * (n / 3), b, n / 3);
		star(a + 2 * (n / 3), b + n / 3, n / 3);
		star(a + 2 * (n / 3), b + 2 * (n / 3), n / 3);
	}
}

int main()
{
	int n;
	cin >> n;

	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = ' ';

	star(0, 0, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << arr[i][j];
		cout << "\n";
	}
}