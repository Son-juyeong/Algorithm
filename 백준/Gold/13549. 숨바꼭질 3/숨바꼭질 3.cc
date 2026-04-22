#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define MAX 100001
using namespace std;

struct s {
	int position;
	int time;
	s(int po, int ti) :position(po), time(ti) {}
};

struct cmp {
	bool operator()(s n1, s n2) {
		if (n1.time > n2.time)
			return true;
		else return false;
	}
};

priority_queue<s, vector<s>, cmp> q;
int value[MAX];

int main()
{
	for (int i = 0; i < MAX; i++)
		value[i] = MAX;
	int answer = MAX;
	int n, k;
	cin >> n >> k;
	value[n] = 0;
	if (n == k)
		cout << 0 << "\n";
	else {
		q.push(s(n, 0));
		while (!q.empty()) {
			int p = q.top().position;
			int t = q.top().time;
			if (p == k && answer > t)
				answer = t;
			if (p * 2 < MAX &&value[p*2]>t) {
				value[p * 2] = t;
				q.push(s(p * 2, t));
			}
			if (p - 1 >= 0 && value[p-1] >(t + 1)) {
				value[p - 1] = t+1;
				q.push(s(p - 1, t + 1));
			}
			if (p + 1 < MAX && value[p+1]>(t + 1)) {
				value[p + 1] = t+1;
				q.push(s(p + 1, t + 1));
			}
			q.pop();
		}
		cout << answer << "\n";
	}
}