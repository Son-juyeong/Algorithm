#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >>n;
	long long answer = 0;
	for (int i = 1; i <= n; i++) {
		answer++;
		if (i % 100 == 50 || (i%1000) / 10 == 50 || (i%10000) / 100 == 50 || (i%100000) / 1000 == 50 || (i%1000000) / 10000 == 50) {
			if (i == n)break;
			answer++;
		}		
	}
	cout << answer << endl;
}