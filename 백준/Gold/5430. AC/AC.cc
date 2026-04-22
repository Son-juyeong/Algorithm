#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

char q[500000];

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		int n;
		cin >> n;
		int front = -1, rear = -1;
		bool r = false;
		bool error = false;
		string qq;
		cin >> qq;
		for (int j = 0; j < qq.size(); j++) {
			if (qq[j] != '[' && qq[j] != ']')
				q[++rear] = qq[j];
		}
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'R')
				r ^= 1;
			else if (s[j] == 'D') {
				if (front == rear) {
					error = true;
					break;
				}
				if (r) {
					while (rear!=front&&q[rear--] != ',');
				}
				else {
					while (front!=rear&&q[++front] != ',');
				}
			}
		}
		if (error)
			cout << "error\n";
		else {
			cout << "[";
			if (r) {
				string tmp;
				while (rear != front) {
					if (q[rear] != ',')
						tmp += q[rear];
					else if (q[rear] = ',') {
						for (int j = tmp.size() - 1; j >= 0; j--)
							cout << tmp[j];
						cout << q[rear];
						tmp.clear();
					}
					rear--;
				}
				for (int j = tmp.size() - 1; j >= 0; j--)
					cout << tmp[j];	
			}
			else {
				while (rear != front)
					cout << q[++front];
			}
			cout << "]\n";
		}
	}
}