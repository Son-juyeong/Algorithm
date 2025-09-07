#include<iostream>
#include<algorithm>

using namespace std;

char node[101];
int N;

void insert(int n, char c) {
	node[n] = c;
}

void inorder(int n) {
	if (n * 2 <= N) {
		inorder(n * 2);
	}
	cout << node[n];
	if (n * 2 + 1 <= N) {
		inorder(n * 2 + 1);
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int tc = 1; tc <= 10; tc++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			int n, left, right;
			char c;
			cin >> n >> c;
			if (n * 2 <= N)
				cin >> left;
			if (n * 2 + 1 <= N)
				cin >> right;
			insert(n, c);
		}
		
		cout << "#" << tc << " ";
		inorder(1);
		cout << "\n";
	}

	return 0;
}