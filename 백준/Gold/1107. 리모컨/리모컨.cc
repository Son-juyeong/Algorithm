#include<iostream>
#include<string>
#include<cmath>
#define MAX 1000000
using namespace std;

bool arr[10];

bool check(int n) {
	string s = to_string(n);
	for (int i = 0; i < s.size(); i++)
		if (arr[s[i] - '0']) return false;
	return true;
}

int num(int n) {
	if (n < 10) return 1;
	else if (n < 100) return 2;
	else if (n < 1000) return 3;
	else if (n < 10000) return 4;
	else if (n < 100000) return 5;
	else if (n < 1000000) return 6;
	else return 7;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		arr[tmp] = true;
	}

	int answer = abs(n - 100);
	for (int i = 0; i < MAX; i++) {
		if (check(i)) {
			int tmp = num(i) + abs(i - n);
			answer = min(answer, tmp);
		}
	}

	cout << answer << endl;
}