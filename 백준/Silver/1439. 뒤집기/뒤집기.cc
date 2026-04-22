#include<iostream>

using namespace std;

int main()
{
	string s;
	int cnt = 0;
	cin >> s;
	char ch = s[0];
	if(s.size()<=1)
		cout << cnt << endl;
	else {
		for (int i = 1; i < s.size(); i++) {
			if (s[i] != s[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(i) - 1] && s[i] == ch)
				cnt++;
		}
		if (ch != s[s.size() - 1])
			cnt++;
		cout << cnt << endl;
	}	
}