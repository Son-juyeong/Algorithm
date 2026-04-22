#include<iostream>

using namespace std;
string p[1000] = { "CY", "SK", "CY", "SK" };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 4; i < n; i++) {
		if (p[i - 1] == "SK" && p[i - 3] == "SK" && p[i - 4] == "SK")
			p[i] = "CY";
		else
			p[i] = "SK";
	}

	cout << p[n-1] << endl;
}