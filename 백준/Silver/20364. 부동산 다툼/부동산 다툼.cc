#include<iostream>

using namespace std;

int n;
bool b[200000000];

void dfs(int t) {
	if (t > n) return;
	b[t] = true;
	dfs(t * 2);
	dfs(t * 2 + 1);
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int q;
	cin >> n >> q;

	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		if (!b[t]) {
			cout << "0\n";
			dfs(t);
		}
		else {
			int node = t;
			while (t >= 1) {
				t /= 2;
				if (b[t])
					node = t;
				else
					break;
			}
			cout << node << "\n";
		}
	}

	return 0;
}