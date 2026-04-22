#include<iostream>

using namespace std;
int min_num[50001] = { 0, 1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (long long int i = 1; i <= n; i++) {
		if ((i * i) <= n) {
			min_num[i * i] = 1;
			if ((i * i) == n)
				break;
		}
		if (min_num[i] == 1)
			continue;
		min_num[i] = 50000;
		for (long long int j = 1; (j * j) < i; j++) {
			min_num[i] = min(min_num[j * j] + min_num[i - j * j], min_num[i]);
		}
	}
	cout << min_num[n] << endl;
}