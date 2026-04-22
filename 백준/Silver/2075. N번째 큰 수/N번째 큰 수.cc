#include<iostream>
#include<queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int, vector<int>, greater<int>> q;

	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			if (i == 0)
				q.push(tmp);
			else {
				if (q.top() < tmp) {
					q.pop();
					q.push(tmp);
				}
			}
		}
	cout << q.top() << endl;
}