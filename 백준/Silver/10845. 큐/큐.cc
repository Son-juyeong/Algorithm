#include<iostream>

using namespace std;

typedef struct Queue {
	int queue[10001];
	int front, rear;
}Queue;

void init_Queue(Queue* q) {
	q->front = -1;
	q->rear = -1;
}

void push_queue(Queue *q, int x) {
	q->queue[++q->rear] = x;
}

int size_queue(Queue* q) {
	return q->rear - q->front;
}

int empty_queue(Queue* q) {
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

int pop_queue(Queue* q) {
	if (empty_queue(q))
		return -1;
	else
		return q->queue[++q->front];
}

int front_queue(Queue* q) {
	if (empty_queue(q))
		return -1;
	else
		return q->queue[q->front+1];
}

int back_queue(Queue* q) {
	if (empty_queue(q))
		return -1;
	else
		return q->queue[q->rear];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Queue q;
	init_Queue(&q);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "push") {
			int t;
			cin >> t;
			push_queue(&q, t);
		}
		else if (s == "pop") {
			cout << pop_queue(&q) << endl;
		}
		else if (s == "size")
			cout << size_queue(&q) << endl;
		else if (s == "empty")
			cout << empty_queue(&q) << endl;
		else if (s == "front")
			cout << front_queue(&q) << endl;
		else if (s == "back")
			cout << back_queue(&q) << endl;
	}
}