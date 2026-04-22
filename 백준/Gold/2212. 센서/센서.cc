#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<long long> v1;
vector<long long>v2;
long long answer;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	if (n <= k) answer = 0;
	else {
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			v1.push_back(t);
		}
		sort(v1.begin(), v1.end());
		for (int i = 1; i < n; i++)
			v2.push_back(v1[i] - v1[i - 1]);
		sort(v2.begin(), v2.end());
		for (int i = 0; i < v2.size() - k + 1; i++) {
			answer += v2[i];
		}
	}
	cout << answer << "\n";
}