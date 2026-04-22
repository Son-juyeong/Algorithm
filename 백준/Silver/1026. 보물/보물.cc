#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int A[50] = { 0 };
	int B[50] = { 0 };
	int N, sum=0;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int j = 0; j < N; j++)
		cin >> B[j];

	sort(A, A + N);
	sort(B, B + N, greater<int>());

	for (int i = 0; i < N; i++)
		sum += A[i] * B[i];
	cout << sum << endl;

	return 0;
}