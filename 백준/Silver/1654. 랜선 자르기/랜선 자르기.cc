#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<long long> v;
	long long k, n;
	cin >> k >> n;
	for (long long i = 0; i < k; i++) {
		long long tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	long long answer = v.back();
	long long a = answer/2;
	while (a != 0) {
		long long cnt = 0;
		for (long long i = 0; i < v.size(); i++) {
			cnt += v[i] / answer;
		}
		if (cnt >= n) {
			if (a > 1) {
				answer += a;
			}
			else {
				while (cnt >= n) {
					answer++;
					cnt = 0;
					for (long long i = 0; i < v.size(); i++)
						cnt += v[i] / answer;
				}
				answer--;
			}
		}
		else {
			if (a > 1) {
				answer -= a;
			}
			else {
				while (cnt < n) {
					answer--;
					cnt = 0;
					for (long long i = 0; i < v.size(); i++)
						cnt += v[i] / answer;
				}
			}
		}
		a /= 2;
	}
	cout << answer << endl;
}