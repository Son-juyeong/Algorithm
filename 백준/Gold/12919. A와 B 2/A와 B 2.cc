#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string s, t;

void rcur(string a, string b) {
	if (a.size() >= b.size()) {
		if (a == b) {
			cout << 1 << endl;
			exit(0);
		}
	}
	else{
		if (b.back() == 'A') {
			string tmp = b;
			tmp.pop_back();
			rcur(a, tmp);
		}
		if (b[0] == 'B') {
			string tmp = b;
			reverse(tmp.begin(), tmp.end());
			tmp.pop_back();
			rcur(a, tmp);
		}
	}
}

int main()
{
	cin >> s;
	cin.ignore();
	cin >> t;
	rcur(s, t);
	cout << 0 << endl;
}