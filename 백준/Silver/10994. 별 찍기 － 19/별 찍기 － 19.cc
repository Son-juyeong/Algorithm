#include<iostream>

using namespace std;

char star[400][400] = { ' ' };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = n; i > 0 ; i--) {
		for (int j = (n-i)*2; j < 2*n+2*i-3; j++) {
			if (j == (n-i)*2 || j == 2 * n + 2 * i - 4)
				for (int k = (n-i)*2; k < 2 * n + 2 * i - 3; k++)
					star[j][k] = '*';
			else {
				star[j][(n-i)*2] = '*';
				star[j][2 * n + 2 * i - 4] = '*';
			}
		}
	}
	for (int i = 0; i < 4*n-3; i++) {
		for (int j = 0; j < 4 * n - 3; j++)
			if (star[i][j] == '*')
				cout << star[i][j];
			else
				cout << " ";
		cout << "\n";
	}
}