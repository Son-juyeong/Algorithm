#include<iostream>
#include<cmath>

using namespace std;

long long arr[1000000];

int main()
{
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		long long pointer = n - 1;
		long long profit = 0;
		long long temp = 0;
		for (int i = n - 2; i >= 0; i--) {
			if (arr[i] >= arr[pointer]) {
				profit += arr[pointer] * (pointer - i-1) - temp;
				pointer = i;
				temp = 0;
			}
			else {
				temp += arr[i];
				if (i == 0) {
					profit += arr[pointer] * (pointer - i) - temp;
				}
			}
		}
		cout << profit << "\n";
	}

	return 0;
}