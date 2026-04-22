#include<iostream>

using namespace std;

int n;
int arr[13];
int answer[6];

void func(int ins, int cnt)
{
	if (cnt == 6) {
		for (int i = 0; i < cnt; i++)
			cout << answer[i] << " ";
		cout << "\n";
	}
	else {
		for (int i = ins; i < n; i++) {
			answer[cnt] = arr[i];
			func(i + 1, cnt + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		func(0, 0);
		cout << "\n";
	}
}