#include<iostream>
#include<cstring>
#include<set>

using namespace std;

int main()
{
	set<string> word;
	string cmp;
	int cnt = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		word.insert(s);
	}
	for (auto iter = word.begin(); iter != word.end(); iter++) {
		if (iter == word.begin()) {
			cmp = *iter; cnt++; continue;
		}
		if (strncmp(cmp.c_str(), (*iter).c_str(), cmp.size()) == 0)
			cmp = *iter;
		else {
			cmp = *iter;
			cnt++;
		}
	}
	cout << cnt << endl;
}