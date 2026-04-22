#include<iostream>

using namespace std;

#define size 500001

int q[size];
int front = 0, rear = 0;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		q[rear++] = i+1;
	int a;
	while (front != rear) {
		a = q[front];
		front = (front + 1) % size;
		if (front == rear)
			break;
		q[rear] = q[front];
		front = (front + 1) % size;
		rear = (rear + 1) % size;
	}
	cout << a << endl;
}