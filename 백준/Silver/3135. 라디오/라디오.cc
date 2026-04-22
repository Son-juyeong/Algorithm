#include<iostream>

using namespace std;

int main()
{
	int a, b, n;
	int hz[5];
	cin >> a >> b;
	int min = a - b;
	if (min < 0)
		min = -min;
	int mtmp = min;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> hz[i];
		int tmp = hz[i] - b;
		if (tmp < 0)
			tmp = -tmp;
		if (min > tmp)
			min = tmp;
	}
	if (min != mtmp)
		min++;
	cout << min << endl;
}