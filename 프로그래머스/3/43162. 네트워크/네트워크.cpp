#include <bits/stdc++.h>
using namespace std;
const int MaxN = 205;
std::vector<int> graph[MaxN];
bool visited[MaxN];
void dfs(int idx)
{
    visited[idx] = true;
    for(int i = 0; i < graph[idx].size(); i++)
    {
        if(visited[graph[idx][i]])
            continue;
        dfs(graph[idx][i]);
    }
}
int solution(int n, vector<vector<int>> computers) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
                continue;
            if(!computers[i][j])
                continue;
            graph[i].push_back(j);
        }
    }
    int answer = 0;
    for(int i = 0; i < n; i++)
    {
        if(visited[i])
            continue;
        dfs(i);
        answer++;
    }
    return answer;
}