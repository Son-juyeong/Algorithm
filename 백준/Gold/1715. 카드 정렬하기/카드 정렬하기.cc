#include<iostream>
#include<queue>
#include<vector>
using namespace std;

priority_queue<long long, vector<long long>, greater<>> q;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	long long answer = 0;

	for (int i = 0; i < n; i++) {
		long long t;
		cin >> t;
		q.push(t);
	}
	while (q.size() > 1) {
		long long t1 = q.top();
		q.pop();
		long long t2 = q.top();
		q.pop();
		answer += t1 + t2;
		q.push(t1 + t2);
	}
	cout << answer << "\n";
}