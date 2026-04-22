#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	long long a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	if (n == 1) {
		long long answer = a + b + c + d + e + f;
		long long max_num = max({ a, b, c, d, e, f });
		cout << answer - max_num << "\n";
	}
	else {
		long long min_num = min({ a, b, c, d, e, f });
		long long plus = min_num * (n * (n - 1) * 4 + (n-2)*(n-2));
		long long num1, num2, num3, num4;
		if (min_num == a||min_num==f) {
			if (b > c) num1 = plus + c * ((n+n-2) * 4) + b * 4;
			else num1 = plus + b * ((n + n - 2) * 4) + c * 4;
			if (b > d) num2 = plus + d * ((n + n - 2) * 4) + b * 4;
			else num2 = plus + b * ((n + n - 2) * 4) + d * 4;
			if (c > e) num3 = plus + e * ((n + n - 2) * 4) + c * 4;
			else num3 = plus + c * ((n + n - 2) * 4) + e * 4;
			if (d > e) num4 = plus + e * ((n + n - 2) * 4) + d * 4;
			else num4 = plus + d * ((n + n - 2) * 4) + e * 4;
		}
		else if (min_num == b||min_num==e) {
			if (a > c) num1 = plus + c * ((n + n - 2) * 4) + a * 4;
			else num1 = plus + a * ((n + n - 2) * 4) + c * 4;
			if (a > d) num2 = plus + d * ((n + n - 2) * 4) + a * 4;
			else num2 = plus + a * ((n + n - 2) * 4) + d * 4;
			if (c > f) num3 = plus + f * ((n + n - 2) * 4) + c * 4;
			else num3 = plus + c * ((n + n - 2) * 4) + f * 4;
			if (d > f) num4 = plus + f * ((n + n - 2) * 4) + d * 4;
			else num4 = plus + d * ((n + n - 2) * 4) + f * 4;
		}
		else if (min_num == c||min_num==d) {
			if (b > a) num1 = plus + a * ((n + n - 2) * 4) + b * 4;
			else num1 = plus + b * ((n + n - 2) * 4) + a * 4;
			if (b > f) num2 = plus + f * ((n + n - 2) * 4) + b * 4;
			else num2 = plus + b * ((n + n - 2) * 4) + f * 4;
			if (a > e) num3 = plus + e * ((n + n - 2) * 4) + a * 4;
			else num3 = plus + a * ((n + n - 2) * 4) + e * 4;
			if (f > e) num4 = plus + e * ((n + n - 2) * 4) + f * 4;
			else num4 = plus + f * ((n + n - 2) * 4) + e * 4;
		}
		cout << min({ num1, num2, num3, num4 }) << "\n";
	}
}