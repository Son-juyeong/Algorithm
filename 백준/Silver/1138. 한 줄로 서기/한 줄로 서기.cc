#include<iostream>

using namespace std;

int result[10];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int cnt;
		cin >> cnt;
		int idx = 0;
		while (cnt != 0||result[idx]!=0) {
			if (result[idx] == 0)
				--cnt;
			++idx;
		}
		result[idx] = i + 1;
	}

	for (int i = 0; i < N; i++)
		cout << result[i] << " ";

	return 0;
}