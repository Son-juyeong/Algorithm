#include<iostream>
#include<queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>, greater<int>> q;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == 0) {
			if (q.empty())
				cout << 0 << "\n";
			else {
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else
			q.push(tmp);
	}
}