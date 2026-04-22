#include<iostream>

using namespace std;

int coin[10];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, num = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		if (coin[i] <= m) {
			num += m / coin[i];
			m %= coin[i];
		}
	}
	cout << num << endl;
}