#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<>> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, s, t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> t;
		v.push_back(make_pair(s, t));
	}
	sort(v.begin(), v.end());
	q.push(v[0].second);
	for (int j = 1; j < v.size(); j++) {
		if (q.top() <= v[j].first) {
			q.push(v[j].second);
			q.pop();
		}
		else q.push(v[j].second);
	}
	cout << q.size() << endl;
}