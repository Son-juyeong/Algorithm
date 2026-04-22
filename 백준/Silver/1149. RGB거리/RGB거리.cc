#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int r=0, g=0, b=0, pr=0, pg=0, pb=0;
	for (int i = 0; i < n; i++) {
		cin >> r >> g >> b;
		r += min(pg, pb);
		g += min(pr, pb);
		b += min(pr, pg);
		pr = r;
		pg = g;
		pb = b;
	}
	cout << min({ r, g, b }) << endl;
}