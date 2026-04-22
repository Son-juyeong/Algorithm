#include<iostream>

using namespace std;

int arr[300000] = { 1, 1 };

int main()
{
	while (1) {
		int n;
		int cnt = 0;
		cin >> n;
		if (!n)
			break;
		for (int i = 2; i <= 2*n; i++) {
			if (arr[i] == 1) continue;
			for (int j = i * 2; j <= 2*n; j += i)
				arr[j] = 1;
		}
		for (int i = n+1; i <= 2 * n; i++)
			if (!arr[i]) cnt++;
		cout << cnt << endl;
	}
}