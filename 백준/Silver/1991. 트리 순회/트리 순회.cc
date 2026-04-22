#include<iostream>

using namespace std;


class NODE {
private:
	char _w;
	NODE* _ln=NULL;
	NODE* _rn=NULL;
public:
	void set(char w);
	void left(NODE* ln);
	void right(NODE* rn);
	void pre(NODE* n);
	void in(NODE* n);
	void post(NODE* n);
	NODE search(NODE* n, char t);
};

void NODE::set(char w) {
	_w = w;
}

void NODE::left(NODE* ln) {
	_ln = ln;
}
void NODE::right(NODE* rn) {
	_rn = rn;
}

void NODE::pre(NODE* n) {
	if (n == NULL) return;
	cout << n->_w;
	pre(n->_ln);
	pre(n->_rn);
}
void NODE::in(NODE* n) {
	if (n == NULL) return;
	in(n->_ln);
	cout << n->_w;
	in(n->_rn);
}
void NODE::post(NODE* n) {
	if (n == NULL) return;
	post(n->_ln);
	post(n->_rn);
	cout << n->_w;
}


int main()
{
	int n;
	cin >> n;
	NODE node[26];
	node[0].set('A');
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a;
		cin.ignore();
		cin >> b;
		cin.ignore();
		cin >> c;
		if (b != '.'){
			node[b - 'A'].set(b);
			node[a-'A'].left(&node[b - 'A']);
		}
		if (c != '.') {
			node[c - 'A'].set(c);
			node[a - 'A'].right(&node[c - 'A']);
		}
	}
	node[0].pre(node);
	cout << endl;
	node[0].in(node);
	cout << endl;
	node[0].post(node);
}