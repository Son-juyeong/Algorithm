#include<iostream>

using namespace std;

int main() {
	string king;
	string stone;
	int n;
	cin >> king;
	cin.ignore();
	cin>>stone >> n;
	for (int i = 0; i < n; i++) {
		string order;
		cin >> order;
		if (order == "R") {
			if (king[0] + 1 == stone[0] && king[1] == stone[1]) {
				if (stone[0] == 'H')
					continue;
				else {
					king[0] += 1;
					stone[0] += 1;
				}
			}
			else {
				if (king[0] == 'H')
					continue;
				else
					king[0]+=1;
			}
		}
		else if (order == "L") {
			if (king[0] - 1 == stone[0] && king[1] == stone[1]) {
				if (stone[0] == 'A')
					continue;
				else {
					king[0] -= 1;
					stone[0] -= 1;
				}
			}
			else {
				if (king[0] == 'A')
					continue;
				else
					king[0] -= 1;
			}
		}
		else if (order == "B") {
			if (king[1] - 1 == stone[1] && king[0] == stone[0]) {
				if (stone[1] == '1')
					continue;
				else {
					king[1] -= 1;
					stone[1] -= 1;
				}
			}
			else {
				if (king[1] == '1')
					continue;
				else
					king[1] -= 1;
			}

		}
		else if (order == "T") {
			if (king[1] + 1 == stone[1] && king[0] == stone[0]) {
				if (stone[1] == '8')
					continue;
				else {
					king[1] += 1;
					stone[1] += 1;
				}
			}
			else {
				if (king[1] == '8')
					continue;
				else
					king[1] += 1;
			}

		}
		else if (order == "RB") {
			if (king[0] + 1 == stone[0] && king[1]-1 == stone[1]) {
				if (stone[0] == 'H'|| stone[1] == '1')
					continue;
				else {
					king[0] += 1;
					stone[0] += 1;
					king[1] -= 1;
					stone[1] -= 1;
				}
			}
			else {
				if (king[0] == 'H' || king[1] == '1')
					continue;
				else {
					king[0] += 1;
					king[1] -= 1;
				}
			}

		}
		else if (order == "LB") {
			if (king[0] - 1 == stone[0] && king[1]-1 == stone[1] ) {
				if (stone[0] == 'A' || stone[1] == '1')
					continue;
				else {
					king[0] -= 1;
					stone[0] -= 1;
					king[1] -= 1;
					stone[1] -= 1;
				}
			}
			else {
				if (king[0] == 'A' || king[1] == '1')
					continue;
				else {
					king[0] -= 1;
					king[1] -= 1;
				}
			}
		}
		else if (order == "RT") {
			if (king[0] + 1 == stone[0] && king[1]+1 == stone[1]) {
				if (stone[0] == 'H' || stone[1] == '8')
					continue;
				else {
					king[0] += 1;
					stone[0] += 1;
					king[1] += 1;
					stone[1] += 1;
				}
			}
			else {
				if (king[0] == 'H' || king[1] == '8')
					continue;
				else {
					king[0] += 1;
					king[1] += 1;
				}
			}
		}
		else if (order == "LT") {
			if (king[0] - 1 == stone[0] && king[1]+1 == stone[1]) {
				if (stone[0] == 'A' || stone[1] == '8')
					continue;
				else {
					king[0] -= 1;
					stone[0] -= 1;
					king[1] += 1;
					stone[1] += 1;
				}
			}
			else {
				if (king[0] == 'A' || king[1] == '8')
					continue;
				else {
					king[0] -= 1;
					king[1] += 1;
				}
			}
		}
	}
	cout << king << endl;
	cout << stone << endl;
}