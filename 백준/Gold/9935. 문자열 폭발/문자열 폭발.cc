#include<iostream>
using namespace std;

char stack[1000001];
int p[1000001];
int top = -1, p_top = -1;
string s, t, answer;

int main()
{
	cin >> s;
	cin.ignore();
	cin >> t;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == t[0]) {
			if (t.size() == 1) continue;
			else{
				stack[++top] = s[i];
				p[++p_top] = 1;
			}
		}
		else if (p_top>=0&&s[i] == t[p[p_top]]) {
			if (p[p_top] == t.size() - 1) {
				top -= p[p_top];
				p_top--;
			}
			else {
				stack[++top] = s[i];
				p[p_top]++;
			}
		}
		else {
			if (top == -1) answer += s[i];
			else {
				for (int j = 0; j <= top; j++)
					answer += stack[j];
				answer += s[i];
				top = -1; p_top = -1;
			}
		}
	}
	if (top != -1) for (int i = 0; i <= top; i++) answer += stack[i];
	if (answer.size() == 0) cout << "FRULA\n";
	else cout << answer << "\n";
}