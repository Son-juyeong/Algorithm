#include<iostream>
#include<math.h>
using namespace std;

int arr[100000];

int main()
{
	ios::sync_with_stdio;
	cin.tie(0); cout.tie(0);
	int start = 0, end = 0;
	int n, s;
	int sum = 0;
	int min_count = 100001;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		end = i;
		sum += arr[i];

		while (sum >= s) {
			sum -= arr[start];
			min_count = min(min_count, end - start + 1);
			start++;
		}
	}
	if (min_count == 100001) min_count = 0;
	cout << min_count << "\n";
}