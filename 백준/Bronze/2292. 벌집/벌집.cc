#include<iostream>

using namespace std;

int main()
{
	int n;
	int sum = 1;
	int cnt = 1;
	cin >> n;
	for (int i = 1; i < n; i++) {
		if (n <= sum)
			break;
		else {
			sum += 6 * i;
			cnt++;
		}
	}
	cout << cnt << endl;
}