#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int S[20] = { 0 };

	int m, n;
	cin >> m;

	string o;

	for (int i = 0; i < m; i++) {
		cin >> o;
		if (o == "add") {
			cin >> n;
			S[n-1] |= 1;
		}
		else if (o == "remove") {
			cin >> n;
			S[n-1] &= 0;
		}
		else if (o == "check") {
			cin >> n;
			cout << S[n - 1] << "\n";
		}
		else if (o == "toggle") {
			cin >> n;
			S[n - 1] ^= 1;
		}
		else if (o == "all") {
			for (int j = 0; j < 20; j++)
				S[j] |= 1;
		}
		else if (o == "empty") {
			for (int j = 0; j < 20; j++)
				S[j] &= 0;
		}
	}
}