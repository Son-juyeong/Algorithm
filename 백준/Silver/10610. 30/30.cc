#include<iostream>
#include<algorithm>

using namespace std;


int main() {

	int sum = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		sum += s[i] - '0';
	}
	if (sum % 3 != 0)
		cout << -1;
	else {
		sort(s.begin(), s.end());
		if (s[0] != '0')
			cout << -1;
		else {
			for (int i = s.size() - 1; i >= 0; i--)
				cout << s[i];
		}
	}

}
