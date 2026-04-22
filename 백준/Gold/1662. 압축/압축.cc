#include<iostream>
using namespace std;

char stack[51];
int num_stack[50];
int top = -1;

int main()
{
	string s;
	cin >> s;
	int answer = 0, temp = 1, cnt = 0;
	bool zero = false;
	for (int i = 0; i < s.size(); i++)
	{
		if (zero) {
			if (s[i] == '(') {
				stack[++top] = s[i];
				cnt++;
			}
			else if (s[i] == ')') {
				top--;
				cnt--;
				if (cnt == 0) zero = false;
			}
		}
		else {
			if (s[i] == '(') {
				stack[++top] = s[i];
				cnt--;
				answer += temp * cnt;
				cnt = 0;
				if (s[i - 1] == '0') { zero = true; cnt++; continue; }
				temp *= s[i - 1] - '0';
				num_stack[top] = s[i - 1] - '0';
			}
			else if (s[i] == ')') {
				answer += temp * cnt;
				cnt = 0;
				temp /= num_stack[top];
				top--;
			}
			else {
				cnt++;
				if (i == s.size() - 1) answer += cnt;
			}
		}
	}
	
	cout << answer << "\n";
}