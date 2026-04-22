#include<iostream>

using namespace std;

double stack[100];
double alphabet[26];

int main()
{
	int top = -1;
	string s;
	int n;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		cin >> alphabet[i];
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+') {
			double tmp = stack[top - 1] + stack[top];
			stack[--top] = tmp;
		}
		else if (s[i] == '-') {
			double tmp = stack[top - 1] - stack[top];
			stack[--top] = tmp;
		}
		else if (s[i] == '*') {
			double tmp = stack[top - 1] * stack[top];
			stack[--top] = tmp;
		}
		else if (s[i] == '/') {
			double tmp = stack[top - 1] / stack[top];
			stack[--top] = tmp;
		}
		else {
			stack[++top] = alphabet[s[i] - 'A'];
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << stack[0] << endl;
}