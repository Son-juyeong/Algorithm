#include<iostream>
#include<map>
#include<algorithm>
#include<cstring>

using namespace std;

#define MAX 1000000

int arr1[MAX];
int arr2[MAX];
map<int, int>a;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	memcpy(arr2, arr1, n*4);
	sort(arr2, arr2 + n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (i==0||i != 0 && arr2[i] != arr2[i - 1])
			a[arr2[i]] = cnt++;
	}
	for (int i = 0; i < n; i++) {
		cout << a[arr1[i]] << " ";
	}
}