#include<iostream>
#include<string>
#include<utility>
#include<map>

using namespace std;

int main()
{
	map<string, int> book;
	string max_book;
	max_book.resize(51);
	int max_nbook = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		book[name]++;
	}
	for (auto iter = book.begin(); iter != book.end(); ++iter)
	{
		if (iter->second > max_nbook)
		{
			max_nbook = iter->second;
			max_book.clear();
			max_book.assign(iter->first);

		}
		else if (iter->second = max_nbook) {
			if (iter->first < iter->first) {
				max_nbook = iter->second;
				max_book.clear();
				max_book.assign(iter->first);
			}
		}
	}
	cout << max_book << endl;
}