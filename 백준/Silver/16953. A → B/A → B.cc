#include<iostream>
#include<queue>
#include<utility>

using namespace std;
queue<pair<long long, long long>>q;

int main()
{
	long long a, b;
	long long answer = -1;
	cin >> a >> b;
	q.push(make_pair(a, 0));
	while (!q.empty())
	{
		long long tmp1 = q.front().first * 10 + 1;
		long long tmp2 = q.front().first * 2;
		long long cnt = q.front().second + 1;
		if (tmp1 < b)
			q.push(make_pair(tmp1, cnt));
		if (tmp2 < b)
			q.push(make_pair(tmp2, cnt));
		if (tmp1 == b|| tmp2 == b) {
			answer = cnt + 1;
			break;
		}
		q.pop();
	}
	cout << answer << endl;
}