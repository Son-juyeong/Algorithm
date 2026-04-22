#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int card[100];
	int n, m, max = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> card[i];
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				int tmp = card[i] + card[j] + card[k];
				if (tmp <= m && tmp > max)
					max = tmp;
			}
		}
	}
	cout << max << endl;
}