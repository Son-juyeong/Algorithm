#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> customer;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int charge;
		cin >> charge;
		customer.push_back(charge);
	}
	sort(customer.begin(), customer.end(), greater<int>());

	int max_profit = 0;
	int max_price = 0;
	for (int i = 0; i < m; i++) {
		if ((i + 1) > n)
			break;
		int t = customer[i] * (i + 1);
		if (t >= max_profit) {
			max_profit = t;
			max_price = customer[i];
		}
	}

	cout << max_price << " " << max_profit << endl;
}