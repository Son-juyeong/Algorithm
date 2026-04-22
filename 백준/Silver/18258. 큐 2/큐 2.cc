#include<iostream>

using namespace std;

int queue[2000000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int front = -1, rear = -1;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		cin.ignore();
		if (s == "push") {
			int t;
			cin >> t;
			queue[++rear] = t;
		}
		else if (s == "pop") {
			if (front == rear)
				cout << -1<<"\n";
			else
				cout << queue[++front] << "\n";
		}
		else if (s == "size") {
			cout << rear - front << "\n";
		}
		else if (s == "empty") {
			if (front == rear)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (s == "front") {
			if (front == rear)
				cout << -1 << "\n";
			else
				cout << queue[front + 1] << "\n";
		}
		else if (s == "back") {
			if (front == rear)
				cout << -1 << "\n";
			else
				cout << queue[rear] << "\n";
		}
	}
}