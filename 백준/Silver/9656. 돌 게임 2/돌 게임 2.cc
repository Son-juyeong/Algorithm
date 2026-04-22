#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	int cnt = n / 3;
	n %= 3;
	if ((cnt + n) % 2 == 0) {
		cout << "SK" << endl;
	}
	else
		cout << "CY" << endl;
}