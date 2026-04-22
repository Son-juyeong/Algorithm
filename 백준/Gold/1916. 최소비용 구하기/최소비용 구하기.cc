#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define SZ 1001

using namespace std;

struct timetable {
	int number;
	long long price;
	timetable(int num, long long cost):number(num), price(cost) {}
};

struct cmp {
	bool operator()(timetable t1, timetable t2) {
		return t1.price > t2.price;
	}
};

bool compare(timetable t1, timetable t2) {
	return t1.price < t2.price;
}

long long visited[SZ];
vector<timetable> bus[SZ];
priority_queue<timetable, vector<timetable>, cmp> pq;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		visited[i] = 10000000000;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		bus[a].push_back(timetable(b, c));
	}
	for (int i = 1; i <= n; i++) {
		if(bus[i].size()>0)
			sort(bus[i].begin(), bus[i].end(), compare);
	}
	int start, end;
	cin >> start >> end;
	if (start == end) cout << 0 << "\n";
	else {
		visited[start] = true;
		pq.push(timetable(start, 0));
		long long answer = 100000000000;
		while (!pq.empty()) {
			int b_num = pq.top().number;
			long long p_num = pq.top().price;
			for (int i = 0; i < bus[b_num].size(); i++) {
				long long t_p = p_num + bus[b_num][i].price;
				if (visited[bus[b_num][i].number]>t_p) {
					visited[bus[b_num][i].number] = t_p;
					pq.push(timetable(bus[b_num][i].number, t_p));
					if (bus[b_num][i].number == end && t_p < answer)
						answer = t_p;
				}
			}
			pq.pop();
		}
		cout << answer << "\n";
	}
}