#include<iostream>

using namespace std;

int arr[20];

int n, s, cnt;

void func(int seq, int sum)
{
	for (int i = seq; i < n; i++) {
		int tmp = sum;
		tmp += arr[i];
		if (tmp == s)
			cnt++;
		func(i+1, tmp);
	}
}

int main()
{
	ios::sync_with_stdio(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	func(0, 0);
	cout << cnt << endl;
}