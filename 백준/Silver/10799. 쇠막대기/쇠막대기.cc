#include<iostream>

using namespace std;

char c_stack[100001];
int i_stack[100001] = { 0 };
int i_top = 0;
int c_top = -1;

int main()
{
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (i < s.size() - 1 && s[i] == '(' && s[i + 1] == ')') {
			if (c_top > -1) {
				i_stack[i_top]++;
			}
			i++;
		}
		else if (i > 0 && s[i - 1] == ')' && s[i] == '(') {
			if(!(i_top==0&&i_stack[i_top]==0))
				i_top++;
			c_stack[++c_top] = s[i];
		}
		else if (s[i] == '(') {
			c_stack[++c_top] = s[i];
			i_top++;
		}
		else if (s[i] == ')') {
			cnt += i_stack[i_top] + 1;
			if (i_top - 1 >= 0) {
				i_stack[i_top - 1] += i_stack[i_top];
				i_stack[i_top] = 0;
				i_top--;
			}
			else
				i_stack[i_top] = 0;
			c_top--;
		}
	}
	cout << cnt << endl;
}