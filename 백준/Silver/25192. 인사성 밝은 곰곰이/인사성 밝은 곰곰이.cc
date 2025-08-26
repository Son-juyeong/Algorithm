#include<iostream>
#include<set>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	set<string> s;

	int N;
	cin >> N;

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		if (str == "ENTER") {
			cnt += s.size();
			s.clear();
		}
		else {
			s.insert(str);
		}
	}

	cnt += s.size();

	cout << cnt;
	return 0;
}