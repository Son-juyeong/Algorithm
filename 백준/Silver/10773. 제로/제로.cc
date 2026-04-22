#include<iostream>
#include<stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> money;
	int n, t, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t)
			money.push(t);
		else
			money.pop();
	}
	while (!money.empty()) {
		sum += money.top();
		money.pop();
	}
	cout << sum << endl;
}