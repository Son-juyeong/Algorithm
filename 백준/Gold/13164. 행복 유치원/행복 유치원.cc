#include<iostream>
#include<algorithm>
#define MAX 300000
using namespace std;

int arr1[MAX];
int arr2[MAX];
int answer;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr1[i];
	sort(arr1, arr1 + n);
	for (int i = 0; i < n - 1; i++)
		arr2[i] = arr1[i + 1] - arr1[i];
	sort(arr2, arr2 + n - 1);
	for (int i = 0; i < n - k; i++)
		answer += arr2[i];
	cout << answer << endl;
}