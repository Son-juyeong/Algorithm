#include<iostream>
#include<utility>

using namespace std;

int main()
{
	pair<int, int> x;
	x.first = 1;
	int n, m;
	cin >> n >> m;
	x.second = m;
	int d = 0;
	int j, a, go;
	cin >> j;
	for (int i = 0; i < j; i++) {
		cin >> a;
		if (a < x.first) {
			go = x.first - a;
			d += go;
			x.first -= go;
			x.second -= go;
		}
		else if (a > x.second) {
			go = a - x.second;
			d += go;
			x.first += go;
			x.second += go;
		}
	}
	cout << d << endl;
}