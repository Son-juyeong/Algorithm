#include<iostream>
int nums[2000001] = { 0 };

using namespace std;

int main()
{
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		if (m >= 0)
			nums[1000000 + m] = 1;
		else
			nums[-m - 1] = 1;
	}
	for (int i = 999999; i >= 0; i--)
		if (nums[i] == 1)
			std::cout << -(i + 1) << "\n";
	for (int i = 1000000; i < 2000001; i++)
		if (nums[i] == 1)
			std::cout << i - 1000000 << "\n";
	return 0;
}