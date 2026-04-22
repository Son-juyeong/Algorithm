#include<iostream>
using namespace std;

char stack[31];
int top = -1, answer = 0, temp = 1;

int main()
{
	string s;
	cin >> s;
	int i = 0;
	bool correct = true;
	while (correct) {
		switch (s[i]) {
		case '(':
			stack[++top] = s[i];
			temp *= 2;
			break;
		case '[':
			stack[++top] = s[i];
			temp *= 3;
			break;
		case ')':
			if (top == -1||stack[top]!='(') {
				answer = 0;
				correct = false;
			}
			else {
				if (s[i - 1] == '(') answer += temp;
				temp /= 2;
				top--;
			}
			break;
		case ']':
			if (top == -1 || stack[top] != '[') {
				answer = 0;
				correct = false;
			}
			else {
				if (s[i - 1] == '[') answer += temp;
				temp /= 3;
				top--;
			}
			break;
		}
		i++;
		if (i == s.size()) correct = false;
	}
	if (top != -1) answer = 0;
	std::cout << answer << endl;
}