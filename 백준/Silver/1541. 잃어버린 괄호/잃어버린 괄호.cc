#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	bool plus = true;
	int p_num = 0;
	int m_num = 0;
	string tmp;
	for (int i = 0; i < s.size(); i++) {
		if (plus) {
			if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
				tmp += s[i];
				if (i == s.size() - 1)
					p_num += stoi(tmp);
			}
			else {
				p_num += stoi(tmp);
				tmp.clear();
				if (s[i] == '-')
					plus = false;
			}
		}
		else {
			if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
				tmp += s[i];
				if (i == s.size() - 1)
					m_num += stoi(tmp);
			}
			else {
				m_num += stoi(tmp);
				tmp.clear();
			}
		}
	}
	cout << p_num - m_num << endl;
}