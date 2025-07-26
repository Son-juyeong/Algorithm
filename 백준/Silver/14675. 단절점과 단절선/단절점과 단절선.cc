#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int node[100001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		node[n1]++;
		node[n2]++;
	}
	int q;
	cin >> q;
	string answer;
	for (int i = 0; i < q; i++) {
		int t, k;
		cin >> t >> k;
		switch (t) {
		case 1:
			if (node[k] == 1)
				answer += "no\n";
			else
				answer+="yes\n";
			break;
		case 2:
			answer+="yes\n";
			break;
		}
	}
	cout << answer;

	return 0;
}