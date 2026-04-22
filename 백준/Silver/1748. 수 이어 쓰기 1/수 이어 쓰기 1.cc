#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	long long s = 0;
	int cnt = 0;
	int a = n;
	while (a) {
		a /= 10;
		cnt++;
	}
	int b = n - pow(double(10), double(cnt - 1)) + 1;
	s += static_cast<long long>(cnt) * b;
	--cnt;
	while (cnt) {
		s += cnt * (pow(double(10), double(cnt)) - pow(double(10), double(cnt - 1)));
		--cnt;
	}
	cout << s << endl;
}