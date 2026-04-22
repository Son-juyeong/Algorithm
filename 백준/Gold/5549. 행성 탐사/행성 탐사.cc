#include<iostream>

using namespace std;

struct arr {
	int J;
	int O;
	int I;
}arr[1001][1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m, n;
	cin >> m >> n;
	int k;
	cin >> k;
	
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0) {
				arr[i][j] = { 0, 0, 0 };
				continue;
			}
			char tmp;
			cin >> tmp;
			arr[i][j] = { arr[i - 1][j].J + arr[i][j - 1].J - arr[i - 1][j - 1].J, arr[i - 1][j].O + arr[i][j - 1].O - arr[i - 1][j - 1].O, arr[i - 1][j].I + arr[i][j - 1].I - arr[i - 1][j - 1].I };
			if (tmp == 'J')
				arr[i][j].J++;
			else if (tmp == 'O')
				arr[i][j].O++;
			else if (tmp == 'I')
				arr[i][j].I++;
		}
	}

	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a>> b>> c>> d;
		cout << arr[c][d].J - arr[a-1][d].J - arr[c][b-1].J + arr[a-1][b-1].J << " ";
		cout << arr[c][d].O - arr[a-1][d].O - arr[c][b-1].O + arr[a-1][b-1].O << " ";
		cout << arr[c][d].I - arr[a-1][d].I - arr[c][b-1].I + arr[a-1][b-1].I << "\n";
	}
}