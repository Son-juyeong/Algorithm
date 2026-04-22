#include<iostream>
#include<vector>
using namespace std;

vector<int>party[50];
int t_people[51];
int t_person;
int parent[51];
int node_rank[51];

int find_root(int num)
{
	if (parent[num] == num) return num;
	else return parent[num] = find_root(parent[num]);
}

void set_union(int p, int q)
{
	p = find_root(p);
	q = find_root(q);
	if (p != q) {
		if (node_rank[p] > node_rank[q]) parent[q] = p;
		else parent[p] = q;
		if (node_rank[p] == node_rank[q]) node_rank[q]++;
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int answer = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	int p_num;
	cin >> p_num;
	for (int i = 0; i < p_num; i++) {
		cin >> t_people[i];
		if (i == 0) continue;
		set_union(t_people[i], t_people[i - 1]);
	}

	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		for (int j = 0; j < t; j++) {
			int num;
			cin >> num;
			party[i].push_back(num);
			if (j == 0) continue;
			set_union(party[i][j], party[i][j - 1]);
		}
	}

	t_person = find_root(t_people[0]);

	for (int i = 0; i < m; i++) {
		bool talk = true;
		for(int j=0;j<party[i].size();j++)
			if (t_person == find_root(party[i][j])) {
				talk = false;
				break;
			}
		if (talk) answer++;
	}
	cout << answer << "\n";
}