#include<iostream>

using namespace std;

int main() {
	int sign[10] = { 0 };
	string l;
	string r;
	cin >> l;
	cin.ignore();
	cin >> r;
	int eight = 0;
	if (l == r) {
		for (int i = 0; i < l.size(); i++)
			if (l[i] == '8')
				eight++;
	}
	else {
		if (r.size() > l.size()) {
		}
		else {
			for (int i = 0; i < l.size(); i++) {
				if (l[i] == r[i]) {
					if (l[i] == '8')
						sign[i] = 2;
					else
						sign[i] = 1;
				}
			}
			for (int i = 0; i < 10; i++)
				if (sign[i] == 0)
					break;
				else if (sign[i] == 2)
					eight++;
		}
	}
	cout << eight << endl;
}