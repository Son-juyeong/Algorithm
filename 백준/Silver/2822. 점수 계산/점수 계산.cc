#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<pair<int, int>> t_score;
	vector<int> order;
	int score, max_score = 0;
	for (int i = 1; i < 9; i++) {
		cin >> score;
		t_score.push_back({ score, i });
	}
	sort(t_score.begin(), t_score.end(), greater<>());
	for (int i = 0; i < 5; i++) {
		max_score += t_score[i].first;
		order.push_back(t_score[i].second);
	}
	sort(order.begin(), order.end());
	cout << max_score << endl;
	for (int i = 0; i < 5; i++) {
		cout << order[i] << " ";
	}
}