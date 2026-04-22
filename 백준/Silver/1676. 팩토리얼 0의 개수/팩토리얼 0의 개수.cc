#include<iostream>

using namespace std;

int main()
{
	long long fct = 1;
	int num, cnt = 0;
	cin >> num;
	for (int i = 1; i <= num; i++) {
		fct *= i;
		if (!(fct % 1000)) {
			fct %= 10000;
			fct /= 1000;
			cnt += 3;
		}
		else if (!(fct % 100)) {
			fct %= 1000;
			fct /= 100;
			cnt += 2;
		}
		else if (!(fct % 10)) {
			fct %= 100;
			fct /= 10;
			cnt++;
		}
	}
	cout << cnt << endl;
}