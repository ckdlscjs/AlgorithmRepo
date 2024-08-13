#include <bits/stdc++.h>
using namespace std;
const int MaxN = 105;
std::vector<int> graph[MaxN];
int dfs (int skip, int idx, bool* visited, int sum)
{
    if(skip == idx)
        return sum;
    visited[idx] = true;
    for(int i = 0; i < graph[idx].size(); i++)
    {
        if(graph[idx][i] == skip)
            continue;
        if(visited[graph[idx][i]])
            continue;
        sum = dfs(skip, graph[idx][i], visited, sum+1);
    }
    return sum;
}
int solution(int n, vector<vector<int>> wires) 
{
    for(const auto& iter : wires)
    {
        graph[iter[0]].push_back(iter[1]);
        graph[iter[1]].push_back(iter[0]);
    }
    int answer = n;
    for(int i = 1; i <= n; i++)
    {
        bool visited[MaxN];
        std::memset(visited, false, sizeof(visited));
        int result = dfs(i, 1, visited, 1);
        //std::cout << result <<'\n';
        answer = std::min(answer, std::abs(result*2 - n));
    }
    
    return answer;
}