#include<iostream>
#include<cstring>
#include<set>

using namespace std;

int main()
{
	set<string> string_s;
	string s;
	cin >> s;
	for (int i = 1; i <= s.size(); i++) {
		for (int j = 0; j <= s.size() - i; j++) {
			string_s.insert(s.substr(j, i));
		}
	}
	cout << string_s.size();
}