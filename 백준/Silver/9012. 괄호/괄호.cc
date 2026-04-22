#include<iostream>
#include<stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	string b;

	for (int i = 0; i < n; i++) {
		cin >> b;
		stack<char> a;
		for (int j = 0; j < b.size(); j++) {
			if (b[j] == '(')
				a.push(b[j]);
			else if (b[j] == ')') {
				if (a.empty()) {
					cout << "NO\n";
					break;
				}
				else 
					a.pop();
			}
			if (j == b.size() - 1 && a.empty())
				cout << "YES\n";
			else if (j == b.size() - 1 && (!a.empty()))
				cout << "NO\n";
		}
	}
}