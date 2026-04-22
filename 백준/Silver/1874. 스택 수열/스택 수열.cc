#include<iostream>

using namespace std;

int stack[100001];
char pm[200001];
int top = 0;
int pmp = 0;

int main()
{
	int n;
	cin >> n;
	int p = 1;
	stack[0] = -1;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		while (p <= t) {
			stack[++top] = p;
			pm[pmp++] = '+';
			p++;
		}
		
		if (stack[top] == t) {
			top--;
			pm[pmp++] = '-';
		}
	}
	if (top != 0)
		cout << "NO\n";
	else {
		for (int i = 0; i < pmp; i++)
			cout << pm[i] << "\n";
	}
}