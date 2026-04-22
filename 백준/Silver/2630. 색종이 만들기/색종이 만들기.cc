#include<iostream>
using namespace std;

#define SZ 129
#define FC pair<int, int>

bool arr[SZ][SZ];

FC func(int r, int c, int n) {
	if (n == 1)
		return { !arr[r][c], arr[r][c] };
	else {
		if (func(r, c, n / 2).first == 1 && func(r + n / 2, c, n / 2).first == 1 && func(r, c + n / 2, n / 2).first == 1 && func(r + n / 2, c + n / 2, n / 2).first == 1) {
			if (func(r, c, n / 2).second + func(r + n / 2, c, n / 2).second + func(r, c + n / 2, n / 2).second + func(r + n / 2, c + n / 2, n / 2).second > 0)
				return { func(r, c, n / 2).first + func(r + n / 2, c, n / 2).first + func(r, c + n / 2, n / 2).first + func(r + n / 2, c + n / 2, n / 2).first, func(r, c, n / 2).second + func(r + n / 2, c, n / 2).second + func(r, c + n / 2, n / 2).second + func(r + n / 2, c + n / 2, n / 2).second };
			else return { 1, 0 };
		}
		else if (func(r, c, n / 2).second == 1 && func(r + n / 2, c, n / 2).second == 1 && func(r, c + n / 2, n / 2).second == 1 && func(r + n / 2, c + n / 2, n / 2).second == 1)
			if (func(r, c, n / 2).first + func(r + n / 2, c, n / 2).first + func(r, c + n / 2, n / 2).first + func(r + n / 2, c + n / 2, n / 2).first > 0)
				return { func(r, c, n / 2).first + func(r + n / 2, c, n / 2).first + func(r, c + n / 2, n / 2).first + func(r + n / 2, c + n / 2, n / 2).first, func(r, c, n / 2).second + func(r + n / 2, c, n / 2).second + func(r, c + n / 2, n / 2).second + func(r + n / 2, c + n / 2, n / 2).second };
			else
				return { 0, 1 };
		else
			return { func(r, c, n / 2).first + func(r + n / 2, c, n / 2).first + func(r, c + n / 2, n / 2).first + func(r + n / 2, c + n / 2, n / 2).first, func(r, c, n / 2).second + func(r + n / 2, c, n / 2).second + func(r, c + n / 2, n / 2).second + func(r + n / 2, c + n / 2, n / 2).second };
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
	pair<int, int> cnt = func(1, 1, n);
	cout << cnt.first << endl;
	cout << cnt.second << endl;
}