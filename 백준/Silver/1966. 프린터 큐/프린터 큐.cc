#include<iostream>
#include<algorithm>

using namespace std;

#define size 101

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		int q[size];
		int sortq[size];
		int front = 0, rear = 0;
		for (int j = 0; j < n; j++) {
			cin >> q[rear];
			sortq[j] = q[rear++];
		}
		sort(sortq, sortq + n, greater<int>());

		int k = 0, cnt = 0;
		while (1) {
			if (q[front] != sortq[cnt]) {
				q[rear] = q[front];
				if (m == front)
					m = rear;
				front = (front + 1) % size;
				rear = (rear + 1) % size;
			}
			else {
				cnt++;
				if (m == front)
					break;
				else
					front = (front + 1) % size;
			}
		}
		cout << cnt << endl;
	}
}