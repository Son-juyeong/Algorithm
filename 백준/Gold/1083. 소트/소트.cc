#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int num[50] = { 0 };

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> num[i];

	int s;
	cin >> s;
	int m = 0;

	while (s>0&&m<n) {
		int cnt = 0, maxnum = 0, maxid = 0;
		for(int i=m;i<n;i++)
			if (num[i] > maxnum&&(i-m)<=s) {
				maxnum = num[i];
				maxid = i;
			}
		for (int i = maxid; i > m; i--) {
			int tmp;
			tmp = num[i];
			num[i] = num[i - 1];
			num[i - 1] = tmp;
			cnt++;
		}
		m++;
		s -= cnt;
	}
	for (int i = 0; i < n; i++)
		cout << num[i] << " ";
}