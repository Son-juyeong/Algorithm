#include<iostream>
#include<string>

using namespace std;


int main() {

	while (1) {
		bool yes = true;
		string s;
		getline(cin, s);
		if (s == ".")
			break;
		char stack[102] = {'.'};
		int top = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '[' || s[i] == '(')
				stack[++top] = s[i];
			else if (s[i] == ']') {
				if (stack[top] == '[')
					top--;
				else {
					yes = false;
					break;
				}
			}
			else if (s[i] == ')') {
				if (stack[top] == '(')
					top--;
				else {
					yes = false;
					break;
				}
			}
		}
		if (top == 0&&yes)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}
