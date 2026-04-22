#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> rope;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		rope.push_back(t);
	}
	sort(rope.begin(), rope.end(), greater<int>());
	int nmax = 0;
	for (int i = 0; i < n; i++) {
		int tmax = rope[i] * (i + 1);
		nmax = max(nmax, tmax);
	}
	cout << nmax << endl;
}