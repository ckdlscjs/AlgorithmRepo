//https://school.programmers.co.kr/learn/courses/30/lessons/86971
#include <bits/stdc++.h>
using namespace std;
std::vector<int> graph[105];
int nodes[105];
void dfs(int idx)
{
    nodes[idx] = 1;
    for(const auto& next : graph[idx])
    {
        if(nodes[next]) continue;
        dfs(next);
        nodes[idx] += nodes[next];
    }
}
int solution(int n, vector<vector<int>> wires)
{
    for(const auto& iter : wires)
    {
        graph[iter[0]].push_back(iter[1]);
        graph[iter[1]].push_back(iter[0]);
    }
    dfs(1);
    int answer = INT_MAX;
    for(int i = 1; i <= n; i++)
        answer = std::min(answer, std::abs(nodes[i]*2 - n));
    return answer;
}