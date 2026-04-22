#include<iostream>
#include<cmath>

#define MAX 100000

using namespace std;
int arr[2][MAX];

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < n; k++)
				cin >> arr[j][k];
		for(int j=1;j<n;j++)
			for (int k = 0; k < 2; k++) {
				if (j == 1) {
					arr[k][j] += arr[(k + 1) % 2][j - 1];
				}
				else
					arr[k][j] += max(arr[(k + 1) % 2][j - 1], arr[(k + 1) % 2][j - 2]);
			}
		cout << max(arr[0][n - 1], arr[1][n - 1]) << "\n";
	}
}