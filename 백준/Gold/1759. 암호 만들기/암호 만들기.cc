#include<iostream>
#include<algorithm>

using namespace std;

#define SZ 16

char l_s[SZ];
char c_s[SZ];

int l, c;

void func(int order, int cnt, int s) {
	if (cnt == l) {
		for (int i = 0; i < cnt; i++)
			cout << l_s[i];
		cout << "\n";
	}
	else {
		for (int i = order; i < c; i++) {
			l_s[cnt] = c_s[i];
			int tmp = s;
			if (c_s[i] == 'a' || c_s[i] == 'e' || c_s[i] == 'i' || c_s[i] == 'o' || c_s[i] == 'u') tmp++;
			if (!(cnt == l - 1 && tmp == 0) && !(cnt >= l - 2 && tmp > l - 2))
				func(i + 1, cnt + 1, tmp);
			tmp--;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);

	cin >> l >> c;

	for (int i = 0; i < c; i++) {
		cin >> c_s[i];
		cin.ignore();
	}

	sort(c_s, c_s+c);

	func(0, 0, 0);
}