#include<iostream>
#define MAX 1000000

using namespace std;

struct node {
	int left = 0;
	int right = 0;
};

node n[MAX];
int stack[10000];
int top = -1;

void postorder(int x)
{
	if (n[x].left != 0) postorder(n[x].left);
	if (n[x].right != 0)postorder(n[x].right);
	cout << x << "\n";
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int start = 0;
	while (true) {
		int value;
		cin >> value;
		if (cin.eof() == true) break;
		if (top == -1) { stack[++top] = value; start = value; }
		else {
			if (stack[top] > value) {
				n[stack[top]].left = value;
				stack[++top] = value;
			}
			else {
				while (top != -1 && stack[top] <= value) {
					--top;
				}
				n[stack[++top]].right = value;
				stack[top] = value;
			}
		}
	}
	if (start != 0) postorder(start);
}
