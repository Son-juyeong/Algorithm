#include<iostream>
#include<vector>
#define MAX 1000000
using namespace std;

bool composite_number[MAX];
vector<int> odd_prime;

void func()
{
	for (int i = 3; i < MAX; i+=2) {
		for (int j = 3; j < MAX; j+=2) {
			if (i * j >= MAX) break;
			composite_number[i * j] = true;
		}
	}
}

void set_odd_prime()
{
	for (int i = 3; i < MAX; i+=2)
		if (!composite_number[i]) odd_prime.push_back(i);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	func();
	set_odd_prime();

	int n;
	while (1) {
		cin >> n;
		if (n == 0) break;
		int a = MAX, b = MAX;
		for (int i = 0; i < odd_prime.size(); i++) {
			int temp = odd_prime[i];
			if (!composite_number[n - temp]) {
				a = temp;
				b = n - temp;
				break;
			}
		}
		if(a!=MAX||b!=MAX)
			cout << n << " = " << a << " + " << b << "\n";
		else
			cout << "Goldbach's conjecture is wrong.\n"; 
	}
}