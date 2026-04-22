#include<iostream>
#include<cmath>

using namespace std;

int arr[100001];

int main()
{
	ios::sync_with_stdio(0);

	int a, b;
	cin >> a >> b;
	for (int i = 2; i <= b; i++) {
		if (arr[i] == 0) {
			arr[i] = 1;
			int j = 2;
			for (int j = 2; j <= b; j++) {
				if (i * j <= b) {
					arr[i * j]++;
					int tmp = j;
					while (tmp % i == 0) {
						arr[i * j]++;
						tmp /= i;
					}
				}
				else
					break;	
			}
		}
	}
	int cnt = 0;
	for (int i = a; i <= b; i++) {
		if (arr[arr[i]]==1)
			cnt++;
	}
	cout << cnt << endl;
}