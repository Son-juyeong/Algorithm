#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* stack;
int top = -1;

void push(int x) {
	top++;
	stack[top] = x;
}

void empty() {
	if (top == -1)
		printf("1\n");
	else
		printf("0\n");
}

void size() {
	printf("%d\n", top + 1);
}

void pop() {
	if (top==-1)
		printf("-1\n");
	else
		printf("%d\n", stack[top--]);
}

void top_() {
	if (top==-1)
		printf("-1\n");
	else
		printf("%d\n", stack[top]);
}

int main()
{
	int n, i;
	scanf("%d", &n);
	stack = malloc(sizeof(int) * n);
	char order[10];
	for (i = 0; i < n; i++) {
		scanf("%s", order);
		if (strcmp(order, "push") == 0) {
			int num;
			scanf("%d", &num);
			push(num);
		}
		else if (strcmp(order, "pop") == 0) {
			pop();
		}
		else if (strcmp(order, "top") == 0) {
			top_();
		}
		else if (strcmp(order, "empty") == 0) {
			empty();
		}
		else if (strcmp(order, "size") == 0) {
			size();
		}
	}
	return 0;
}