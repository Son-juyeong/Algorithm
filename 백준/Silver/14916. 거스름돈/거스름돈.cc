#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	if (n == 1 || n == 3) {
		cout << -1 << endl;
	}
	else {
		if (n % 5 == 0) {
			cout << n / 5 << endl;
		}
		else {
			int num;
			num = n / 5;
			n %= 5;
			if (n % 2 != 0) {
				n += 5;
				--num;
			}
			num += (n / 2);
			cout << num << endl;
		}
	}
}