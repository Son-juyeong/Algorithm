#include<iostream>

using namespace std;

int arr[1000001] = {0};

int main()
{
	int m, n;
	cin >> m >> n;
	for (int i = 2; i <= n; i++) {
		arr[i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		if (arr[i] == 0) continue;
		for (int j = i * 2; j <= n; j += i)
			arr[j] = 0;
	}
	for (int i = m; i <= n; i++) {
		if (arr[i] != 0)
			cout << i << "\n";
	}
}