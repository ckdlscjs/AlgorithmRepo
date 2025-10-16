#include <bits/stdc++.h>
using namespace std;
bool visited[202];
void DFS(const std::vector<std::vector<int>>& coms, int cur)
{
    visited[cur] = true;
    for(int i = 0; i < coms[cur].size(); i++)
    {
        if(i == cur) continue;
        if(visited[i]) continue;
        if(coms[cur][i] == 0) continue;
        DFS(coms, i);
    }
}
int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    for(int i = 0; i < n; i++)
    {
        if(visited[i]) continue;
        DFS(computers, i);
        answer++;
    }
    return answer;
}