#include<iostream>

using namespace std;
int min_num[1000001] = { 0, 0, 1, 1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 3; i <= n; i++) {

		if (i % 6 == 0)
			min_num[i] = min(min_num[i / 2] + 1, min_num[i / 3] + 1);
		else if (i % 3 == 0)
			min_num[i] = min(min_num[i - 1] + 1, min_num[i / 3] + 1);
		else if (i % 2 == 0)
			min_num[i] = min(min_num[i - 1] + 1, min_num[i / 2] + 1);
		else
			min_num[i] = min_num[i - 1] + 1;
	}
	cout << min_num[n] << endl;
}