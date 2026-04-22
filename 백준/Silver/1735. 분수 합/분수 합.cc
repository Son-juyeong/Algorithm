#include<iostream>

using namespace std;


int main() {

	int a, b, c, d;
	cin >> a >> b;
	cin >> c >> d;

	int m, s, tmpm, tmps;
	s = tmps= a*d + c*b;
	m = tmpm = b * d;

	while (tmpm % tmps) {
		int t = tmps;
		tmps = tmpm % tmps;
		tmpm = t;
	}

	cout << s / tmps << " " << m / tmps << endl;
}
