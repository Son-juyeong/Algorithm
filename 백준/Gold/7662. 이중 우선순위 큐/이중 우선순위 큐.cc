#include<iostream>
#include<set>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		multiset<int> m;
		bool error = false;
		for (int j = 0; j < n; j++) {
			char w;
			int num;
			cin >> w >> num;
			if (w == 'I') {
				m.insert(num);
			}
			else if (w == 'D') {
				if (num == -1 && !m.empty())
					m.erase(m.begin());
				else if (num == 1 && !m.empty()) {
					auto end = m.end();
					end--;
					m.erase(end);
				}
			}
		}
		if (m.empty())
			cout << "EMPTY\n";
		else {
			int start = *(m.begin());
			int end = *(m.rbegin());
			cout << end << " " << start << "\n";
		}
	}
}