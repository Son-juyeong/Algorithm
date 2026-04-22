#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<long long> v;
int n;

void dfs(long long num) {
	for (int i = 0; i < 10; i++) {
		if (num == 0 || i < num % 10) {
			long long tmp = num * 10 + i;
			v.push_back(tmp);
			if (tmp == 0) continue;
			dfs(tmp);
		}
	}
}

int main()
{
	cin >> n;
	dfs(0);
	sort(v.begin(), v.end());
	if (n >= v.size())
		cout << -1 << endl;
	else
		cout << v[n] << endl;
}