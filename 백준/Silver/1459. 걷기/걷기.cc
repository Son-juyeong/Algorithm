#include<iostream>

using namespace std;

int main() {
	long long x, y, w, s;
	cin >> x >> y >> w >> s;
	long long h = 0;
	if (x == 0 && y == 0);
	else {
		if (w > s) {
			long long j = x < y ? x : y;
			long long k = x > y ? x : y;
			if ((k - j) % 2 == 0)
				h = k * s;
			else
				h = s * (k - 1) + w;
		}
		else if (2 * w > s) {
			long long j = x < y ? x : y;
			long long k = x > y ? x : y;
			h = s * j + w * (k - j);
		}
		else if (2 * w <= s) {
			h = w * (x + y);
		}
	}
	cout << h << endl;
}