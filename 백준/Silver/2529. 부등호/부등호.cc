#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
string s;
string num;
long long max_num = 0;
long long min_num = 10000000000;
bool v[10];

void dfs(int a, int depth)
{
	if (depth == n) {
		long long temp = stoll(num);
		max_num = max(max_num, temp);
		min_num = min(min_num, temp);
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (s[depth] == '<') {
			if (i > a&&!v[i]) {
				num += (i + '0');
				v[i] = true;
				dfs(i, depth + 1);
				v[i] = false;
				num.pop_back();
			}
		}
		else{
			if (i < a && !v[i]) {
				num += (i + '0');
				v[i] = true;
				dfs(i, depth + 1);
				v[i] = false;
				num.pop_back();
			}
		}
	}
}

int main()
{
	cin >> n;
	cin.ignore();
	getline(cin, s);
	s.erase(remove(s.begin(), s.end(), ' '), s.end());
	for (int i = 0; i < 10; i++) {
		num += i + '0';
		v[i] = true;
		dfs(i, 0);
		v[i] = false;
		num.pop_back();
	}

	if ((long long)pow(10, n) > max_num) cout << "0";
	cout << max_num << "\n";
	if ((long long)pow(10, n) > min_num) cout << "0";
	cout << min_num << "\n";
}