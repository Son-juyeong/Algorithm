#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, max = 0;
	vector<int> v;
	vector<int> mv;
	cin >> n;
	v.push_back(n);
	for (int i = 0; i <= n; i++) {
		v.push_back(i);
		int j = 0;
		while (v.back() >= 0) {
			v.push_back(v[j] - v[j + 1]);
			j++;
		}
		if (v.back() < 0) {
			if (v.size()-1 > max) {
				max = v.size()-1;
				mv.swap(v);
				v.clear();
				v.push_back(n);
			}
			else {
				v.clear();
				v.push_back(n);
			}
		}
	}
	cout << max << endl;
	for (int i = 0; i < max; i++)
		cout << mv[i] << " ";
}