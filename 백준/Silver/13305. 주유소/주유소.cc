#include<iostream>

using namespace std;
long long city[100000];
long long road[100000];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
		cin >> road[i];
	for (int i = 0; i < n; i++)
		cin >> city[i];
	long long sum = 0;
	int p = 0;
	for (int i = 1; i < n; i++) {
		if (city[p] >= city[i]||i==n-1) {
			long long roadp = 0;
			for (int j = p; j < i; j++)
				roadp += road[j];
			sum += (roadp * city[p]);
			p = i;
		}
	}
	cout << sum << endl;
}