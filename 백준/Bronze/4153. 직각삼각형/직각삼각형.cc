#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int line1, line2, line3;
	do {
		scanf("%d %d %d", &line1, &line2, &line3);
		if (line1 == 0 && line2 == 0 && line3 == 0)
			break;
		int max_l = max(line1, line2);
		max_l = max(max_l, line3);
		if (line1 != max_l && line2 != max_l) {
			if (pow(line1, 2) + pow(line2, 2) == pow(line3, 2))
				std::cout << "right" << endl;
			else
				std::cout << "wrong" << endl;
		}
		else if (line2 != max_l && line3 != max_l) {
			if (pow(line2, 2) + pow(line3, 2) == pow(line1, 2))
				std::cout << "right" << endl;
			else
				std::cout << "wrong" << endl;
		}
		else if (line3 != max_l && line1 != max_l) {
			if (pow(line3, 2) + pow(line1, 2) == pow(line2, 2))
				std::cout << "right" << endl;
			else
				std::cout << "wrong" << endl;
		}
	} while (1);
	return 0;
}