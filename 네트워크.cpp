#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int visit[200] = {0};
 
void dfs(int start, vector<vector<int>> &computers, int n) {
    visit[start]=1;
    for(int i=0; i<n; i++)
    {
        if(visit[i] == 0 && computers[start][i]) // 방문 안했는데 연결됨
            dfs(i, computers, n);
    }
    
}
 
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i<n; i++)
    {
        if(visit[i] == 0)
        {
            answer++;
            dfs(i, computers, n);
        }
    }
    return answer;
}