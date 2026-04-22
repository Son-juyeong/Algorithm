#include<iostream>

using namespace std;

int main()
{
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		char** candy = new char*[x];
		for (int j = 0; j < x; j++)
			candy[j] = new char[y];
		for (int k = 0; k < x; k++) {
			for (int l = 0; l < y; l++)
				cin >> candy[k][l];
		}
		for (int k = 0; k < x; k++) {
			for (int l = 0; l < y; l++) {
				if (candy[k][l] == 'o') {
					if (l > 0 && l + 1 < y && candy[k][l - 1] == '>' && candy[k][l + 1] == '<')
						cnt++;
					else if (k > 0 && k + 1 < x && candy[k - 1][l] == 'v' && candy[k + 1][l] == '^')
						cnt++;
				}
			}
		}
		cout << cnt << endl;
		cnt = 0;
	}
}