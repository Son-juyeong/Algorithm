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

	for (int i = 0; i < 4 * n - 3; i++) {
		if (i % 2 != 0)
			continue;
		if (i == 0 || i == 4 * n - 4) {
			for (int j = 0; j < 4 * n - 3; j++) {
				if (n <= j && j < 3 * n - 3)
					continue;
				star[i][j] = '*';
			}
		}
		else if (i <= (4 * n - 4) / 2) {
			star[i][i / 2] = '*';
			star[i][4 * n - 4 - i / 2] = '*';
			star[i][i / 2 + (n - 1)] = '*';
			star[i][3 * n - 3 - i / 2] = '*';
		}
		else {
			star[i][(4 * n - 3 - i) / 2] = '*';
			star[i][4 * n - 4 - (4 * n - 3 - i) / 2] = '*';
			star[i][(4 * n - 3 - i) / 2 + (n - 1)] = '*';
			star[i][3 * n - 3 - (4 * n - 3 - i) / 2] = '*';
		}
	}

	for (int i = 0; i < 4 * n - 3; i++) {
		if (i % 2 != 0)
			continue;
		for (int j = 0; j < 4 * n - 3; j++) {
			if (i!=0&&i!=4*n-4)
				if(i<= (4 * n - 4) / 2&&j> 4 * n - 4 - i / 2 ||i>(4*n-4)/2&&j> 4 * n - 4 - (4 * n - 3 - i) / 2)
				break;
			if (star[i][j] == '*')
				cout << star[i][j];
			else
				cout << " ";
		}
		cout << "\n";
	}
	
}