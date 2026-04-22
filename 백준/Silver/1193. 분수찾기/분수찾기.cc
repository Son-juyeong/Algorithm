#include<iostream>

using namespace std;

int main()
{
	int son = 0, mom = 0, sum = 0, s_m = 0;
	int x;
	cin >> x;
	int i = 1;
	for (; i < 4500; i++) {
		sum += i;
		if (sum - i < x && x <= sum) {
			s_m = i + 1;
			x -= (sum - i);
			break;
		}
	}
	if (i % 2) {
		son = s_m - x;
		mom = x;
	}
	else {
		son = x;
		mom = s_m - x;
	}
	cout << son << "/" << mom << endl;
}