#include<iostream>
#include<cmath>

using namespace std;

void hanoi(int n, int begin, int end, int pass) {
	if (n == 1)
		cout << begin << " " << end << "\n";
	else {
		hanoi(n - 1, begin, pass, end);
		cout << begin << " " << end << "\n";
		hanoi(n - 1, pass, end, begin);
	}
}

int main()
{
	int n;
	cin >> n;

	cout << int(pow(2, n)) - 1 << "\n";
	hanoi(n, 1, 3, 2);
}