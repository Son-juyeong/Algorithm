#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool visited[121][121][40];

int answer = 121;

void dfs(vector<vector<int>> info, int n, int m, int tn, int tm, int depth){
    if(depth==info.size()){
        answer = min(answer, tn);
        return;
    }
    int newn = tn+info[depth][0];
    int newm = tm+info[depth][1];
    if(newn<n&&newn<answer&&!visited[newn][tm][depth]){
        visited[newn][tm][depth]=true;
        dfs(info, n, m, newn, tm, depth+1);
    }
    if(newm<m&&tn<answer&&!visited[tn][newm][depth]){
        visited[tn][newm][depth]=true;
        dfs(info, n, m, tn, newm, depth+1);
    }
}

int solution(vector<vector<int>> info, int n, int m) {
    dfs(info, n, m, 0, 0, 0);
    if(answer==121)answer=-1;
    return answer;
}