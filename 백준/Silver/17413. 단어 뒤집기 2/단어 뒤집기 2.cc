#include<iostream>
#include<string>

using namespace std;

char stack[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	getline(cin, s);
	bool tag = false;
	int top = -1;

	for (int i = 0; i < s.size(); i++) {
		if (tag) {
			cout << s[i];
			if (s[i] == '>')
				tag = false;
		}
		else {
			if (s[i] == '<') {
				while (top >= 0) {
					cout << stack[top--];
				}
				cout << s[i];
				tag = true;
			}
			else if (s[i] == ' ') {
				while (top >= 0) {
					cout << stack[top--];
				}
				cout << " ";
			}
			else if (s[i] != ' ') {
				stack[++top] = s[i];
				if(i == s.size() - 1)
					while (top >= 0) {
						cout << stack[top--];
					}
			}
		}
	}

}