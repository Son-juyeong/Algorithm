#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int max = 41;

	int t;
	cin >> t;

	int one[max] = { 0 };
	int zero[max] = { 0 };

	one[0] = 0;
	one[1] = 1;
	zero[0] = 1;
	zero[1] = 0;

	for (int i = 2; i < max; i++) {
		one[i] = one[i - 1] + one[i - 2];
		zero[i] = zero[i - 1] + zero[i - 2];
	}

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << zero[n] << " " << one[n] << "\n";
	}

}
