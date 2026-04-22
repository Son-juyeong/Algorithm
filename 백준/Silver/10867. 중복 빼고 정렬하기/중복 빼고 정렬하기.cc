#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int num[2001] = { 0 };
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		num[a + 1000] = 1;
	}
	for (int i = 0; i < size(num); i++) {
		if (num[i])
			cout << i - 1000 << " ";
	}
}
