#include<iostream>
#include<queue>
#include<algorithm>
#define SZ 100001
using namespace std;
int value[SZ];
queue<pair<int, int>> q;
int cnt;

int main()
{
	for (int i = 0; i < SZ; i++)
		value[i] = SZ;
	int n, k;
	cin >> n >> k;
	value[n] = 0;
	if (n == k)
		cout << 0 << "\n" << 1 << "\n";
	else {
		q.push(make_pair(n, 0));
		while (!q.empty()) {
			int p = q.front().first;
			int t = q.front().second;
			if (p * 2 < SZ){
				if (p * 2 == k) { if (cnt == 0) value[k] = t + 1; if (value[p * 2] == t + 1) cnt++; }
				else {
					if (value[p * 2] == SZ) {
						value[p * 2] = t + 1;
						q.push(make_pair(p * 2, t + 1));
					}
					else if (value[p * 2] == t + 1) {
						q.push(make_pair(p * 2, t + 1));
					}
				}
			}
			if (p + 1 < SZ) {
				if (p + 1 == k) { if (cnt == 0) value[k] = t + 1; if (value[p + 1] == t + 1) cnt++; }
				else {
					if (value[p + 1] == SZ) {
						value[p + 1] = t + 1;
						q.push(make_pair(p + 1, t + 1));
					}
					else if (value[p + 1] == t + 1) {
						q.push(make_pair(p + 1, t + 1));
					}
				}
			}
			if (p - 1 >= 0) {
				if (p - 1 == k) { if (cnt == 0) value[k] = t + 1; if (value[p - 1] == t + 1) cnt++; }
				else {
					if (value[p - 1] == SZ) {
						value[p - 1] = t + 1;
						q.push(make_pair(p - 1, t + 1));
					}
					else if (value[p - 1] == t + 1) {
						q.push(make_pair(p - 1, t + 1));
					}
				}
			}
			q.pop();
		}
		cout << value[k] << "\n" << cnt << "\n";
	}
}