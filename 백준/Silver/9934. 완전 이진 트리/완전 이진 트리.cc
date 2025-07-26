#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int k;
vector<int> v;
vector < vector<int>> answer;

void func(int depth, int idx) {
	answer[depth].push_back(v[idx]);
	if (depth == k - 1) return;
	vector<int> t;
	answer.push_back(t);
	func(depth + 1, idx - pow(2, k - depth - 2));
	func(depth + 1, idx + pow(2, k - depth - 2));
}

int main(int argc, char** argv)
{
	cin >> k;

	int n = pow(2, k) - 1;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}

	vector<int> t;
	answer.push_back(t);
	func(0, n / 2);
	for (int i = 0; i < answer.size(); i++) {
		for (int j = 0; j < answer[i].size(); j++) {
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}