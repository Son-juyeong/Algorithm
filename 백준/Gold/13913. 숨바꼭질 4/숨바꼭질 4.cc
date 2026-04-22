#include<iostream>
#include<queue>
#include<algorithm>
#define MAX 100001
using namespace std;

int value[MAX];
int stack[MAX];
int top = -1;
queue<pair<int, int>> q;

int main()
{
	ios::sync_with_stdio(0); cout.tie(0);
	for (int i = 0; i < MAX; i++)
		value[i] = MAX;
	int n, k;
	cin >> n >> k;
	if (n == k) {
		cout << 0 << "\n" << n << "\n";
	}
	else {
		value[n] = -1;
		q.push(make_pair(n, 0));
		int pos = -1;
		while (!q.empty()) {
			int p = q.front().first;
			int t = q.front().second;
			if (p * 2 < MAX && value[p * 2] == MAX) {
				value[p * 2] = p;
				if (p * 2 == k) {
					cout << t + 1 << "\n"; pos = p * 2; break;
				}
				q.push(make_pair(p * 2, t + 1));
			}
			if (p + 1 < MAX && value[p + 1] == MAX) {
				value[p + 1] = p;
				if (p +1 == k) {
					cout << t + 1 << "\n"; pos = p +1; break;
				}
				q.push(make_pair(p + 1, t + 1));
			}
			if (p - 1 >= 0 && value[p - 1] == MAX) {
				value[p - 1] = p;
				if (p - 1 == k) {
					cout << t + 1 << "\n"; pos = p - 1; break;
				}
				q.push(make_pair(p - 1, t + 1));
			}
			q.pop();
		}
		while (1) {
			stack[++top] = pos;
			pos = value[pos];
			if (pos == -1) break;
		}
		for (int i = top; i >= 0; i--)
			cout << stack[i] << " ";
	}
}