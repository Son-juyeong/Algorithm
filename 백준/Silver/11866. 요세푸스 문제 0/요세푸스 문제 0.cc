#include<iostream>

using namespace std;

typedef struct Queue {
	int queue[5001];
	int front, rear;
}Queue;

void init_Queue(Queue* q) {
	q->front = 0;
	q->rear = 0;
}

void Enqueue_Queue(Queue* q, int a, int n) {
	q->queue[q->rear] = a;
	q->rear = (q->rear + 1)%(n+1);
}

int Empty_Queue(Queue* q) {
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

int Dequeue_Queue(Queue* q, int n) {
	int t = q->queue[q->front];
	q->front = (q->front + 1)%(n+1);
	return t;
}

void Rotate_Queue(Queue* q, int k, int n) {
	for (int i = 0; i < k - 1; i++)
		Enqueue_Queue(q, Dequeue_Queue(q, n), n);
}

Queue q;

int yo[5001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init_Queue(&q);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		Enqueue_Queue(&q, i + 1, n);
	}

	cout << "<";

	while (!Empty_Queue(&q)) {
		Rotate_Queue(&q, k, n);
		if ((q.front + 1) % (n + 1) == q.rear)
			cout << Dequeue_Queue(&q, n);
		else cout << Dequeue_Queue(&q, n)<< ", ";
	}
	cout << ">\n";
}