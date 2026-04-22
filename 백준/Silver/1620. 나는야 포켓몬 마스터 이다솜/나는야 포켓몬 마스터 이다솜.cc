#include<iostream>
#include<string>
#include<map>
#include<cctype>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	map<string, int> mlist1;
	map<int, string> mlist2;
	int n, m;
	cin >> n >> m;
	string monster;
	string q;
	for (int i = 0; i < n; i++) {
		cin >> monster;
		mlist1.insert({ monster, i+1 });
		mlist2.insert({ i+1, monster });
	}
	for (int i = 0; i < m; i++) {
		cin >> q;
		if (isdigit(q[0])) {
			int num = stoi(q);
			cout << mlist2[num] << "\n";
		}
		else
			cout << mlist1[q] << "\n";
	}
}