#include<iostream>
#include<cmath>

using namespace std;

char arr[1024][1024] = { ' ' };

void star(int a, int b, int n) {
	if (n == 1)
		arr[a][b] = '*';
	else {
		star(a, b, n / 2);
		star(a + n / 2, b, n / 2);
		star(a, b + n / 2, n / 2);
	}
}

int main()
{
	int n;
	cin >> n;
	int sz = pow(2, n);

	for (int i = 0; i < sz; i++)
		for (int j = 0; j < sz; j++)
			arr[i][j] = ' ';

	star(0, 0, sz);

	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz-i; j++)
			cout << arr[i][j];
		cout << "\n";
	}
}