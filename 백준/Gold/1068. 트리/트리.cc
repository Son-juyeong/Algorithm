#include<iostream>
#define MAX 51
using namespace std;

struct NODE {
	int num;
	NODE* son[MAX];
	NODE* parent;
};

NODE node[MAX];
int cnt;

void count(NODE* a) {
	bool b = true;
	for (int i = 0; i < MAX - 1; i++) {
		if (a->son[i] != NULL) {
			count(a->son[i]);
			b = false;
		}
	}
	if (b && a != &node[50])
		cnt++;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		node[i].num = i;
		int tmp;
		cin >> tmp;
		if (tmp == -1) { node[50].son[i] = &node[i];  node[i].parent = &node[50]; continue; }
		node[tmp].son[i] = &node[i];
		node[i].parent = &node[tmp];
	}
	int a;
	cin >> a;
	node[a].parent->son[a] = NULL;
	count(&node[50]);
	cout << cnt << endl;
}