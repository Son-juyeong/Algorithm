#include<iostream>
#include<queue>

using namespace std;

int main()
{
	queue<int> q;
	int n, tmp;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (q.size() != 1) {
		cout << q.front() << " ";
		q.pop();
		tmp = q.front();
		q.pop();
		q.push(tmp);
	}
	cout << q.front() << endl;
}