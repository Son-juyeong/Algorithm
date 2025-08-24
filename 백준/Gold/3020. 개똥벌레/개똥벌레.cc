#include<iostream>
#include<algorithm>

using namespace std;

int up[500001];
int down[500001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, H;
	cin >> N >> H;
	
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		if (i % 2 == 0)
			down[t]++;
		else
			up[t]++;
	}

	for (int i = H; i > 1; i--) {
		up[i - 1] += up[i];
		down[i - 1] += down[i];
	}

	int mn = 200000, cnt = 0;
	for (int i = 1; i <= H; i++) {
		int crash = down[i] + up[H - i + 1];
		if (crash < mn) {
			mn = crash;
			cnt = 1;
		}
		else if (crash == mn) {
			cnt++;
		}
	}
	cout << mn << " " << cnt;
}