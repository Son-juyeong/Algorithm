#include<iostream>

using namespace std;

int main()
{
	int n, cnt = 0, sum = 0, j = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sum += i;
		while (sum > n) {
			sum -= j;
			j++;
		}
		if (sum == n)
			cnt++;
	}
	cout << cnt << endl;
}