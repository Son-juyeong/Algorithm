#pragma warning(disable : 4996)
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int array[100000];

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}

	sort(array, array+n);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		cout << binary_search(array, array + n, t) << "\n";
	}
}