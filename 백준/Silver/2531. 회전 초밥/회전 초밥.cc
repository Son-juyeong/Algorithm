#include<iostream>
#include<algorithm>
#include<cmath>

//시작점, 끝점 잡아놓기
//왼쪽으로 시작점 끝점 한칸씩 움직이면서 확인
//arr_cnt의 기존 값이 0이었으면 arr_cnt값, cnt++, 이미 있는 초밥이면 arr_cnt값만 증가시키기
//가장 큰 수가 곧 답이오.

int arr[30000];
int arr_cnt[3001];

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, d, k, c;
	cin >> N >> d >> k >> c;

	arr_cnt[c]++;

	int start = 0;
	int cnt = 1;
	int answer = 0;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		
	}
	for (int i = 0; i < N + k - 1; i++) {
		int t = arr[i%N];
		if (arr_cnt[t] == 0)
			cnt++;
		arr_cnt[t]++;
		if (i == k - 1) {
			//cout << cnt << endl;
			answer = max(answer, cnt);
		}
		else if (i >= k) {
			int idx = arr[start];
			arr_cnt[idx]--;
			if (arr_cnt[idx] == 0) cnt--;
			//cout << cnt << endl;
			answer = max(answer, cnt);
			start++;
		}
	}

	cout << answer;
	return 0;
}