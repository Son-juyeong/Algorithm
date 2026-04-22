#include<iostream>
#define SZ 64
using namespace std;

string arr[SZ];
string s;

void fnc(int r, int c, int n)
{
	bool same = true;
	char t = arr[r][c];
	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			if (t != arr[i][j]) {
				same = false;
				break;
			}
		}
		if (!same) break;
	}
	if (!same) {
		s += "(";
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				fnc(r + (n / 2) * i, c + (n / 2) * j, n / 2);
		s += ")";
	}
	else s += t;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cin.ignore();
	}

	fnc(0, 0, n);

	cout << s << endl;
}