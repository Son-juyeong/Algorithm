#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int num[10000] = { 0 };
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		num[a - 1]++;
	}
	for (int i = 0; i < 10000; i++) {
		while (num[i]) {
			cout << i + 1 << "\n";
			--num[i];
		}
	}
}