#include<iostream>

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n;
	cin >> n;
	if (n % 2 == 0)
		cout << "CY\n";
	else
		cout << "SK\n";
}