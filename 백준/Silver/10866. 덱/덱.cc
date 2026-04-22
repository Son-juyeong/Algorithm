#pragma warning(disable :4996)
#include<iostream>

using namespace std;

typedef struct DQ {
	int deque[20001];
	int front, rear;
}DQ;

void init_DQ(DQ* dq) {
	dq->front = dq->rear = 10000;
}

void push_front(DQ* dq, int a) {
	dq->deque[--dq->front] = a;
}

void push_back(DQ* dq, int a) {
	dq->deque[dq->rear++] = a;
}

int empty(DQ* dq) {
	if (dq->front == dq->rear)
		return 1;
	else return 0;
}

int size_dq(DQ* dq) {
	return dq->rear - dq->front;
}

int pop_front(DQ* dq) {
	if (empty(dq))
		return -1;
	else
		return dq->deque[dq->front++];
}

int pop_back(DQ* dq) {
	if (empty(dq))
		return -1;
	else
		return dq->deque[--dq->rear];
}

int front(DQ* dq) {
	if (empty(dq))
		return -1;
	else
		return dq->deque[dq->front];
}

int back(DQ* dq) {
	if (empty(dq))
		return -1;
	else
		return dq->deque[dq->rear-1];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	DQ dq;

	init_DQ(&dq);

	for (int i = 0; i < n; i++) {
		string ts;
		cin >> ts;
		if (ts == "push_front") {
			int tn;
			cin >> tn;
			push_front(&dq, tn);
		}
		else if (ts == "push_back") {
			int tn;
			cin >> tn;
			push_back(&dq, tn);
		}
		else if (ts == "pop_front")
			cout << pop_front(&dq) << "\n";
		else if (ts == "pop_back")
			cout << pop_back(&dq) << "\n";
		else if (ts == "size")
			cout << size_dq(&dq) << "\n";
		else if (ts == "empty")
			cout << empty(&dq) << "\n";
		else if (ts == "front")
			cout << front(&dq) << "\n";
		else if (ts == "back")
			cout << back(&dq) << "\n";
	}
}