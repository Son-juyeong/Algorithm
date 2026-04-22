#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<pair<int, int>> ba;

	ba.push_back(make_pair(1, 0));
	
	int k;
	cin >> k;
	for (int i = 1; i <=k; i++) {
		ba.push_back(make_pair(ba[i - 1].second, ba[i - 1].first + ba[i - 1].second));
	}

	int n = ba.size();
	cout << ba[n - 1].first << " " << ba[n - 1].second << endl;
}