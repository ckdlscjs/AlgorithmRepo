#include <bits/stdc++.h>

using namespace std;
std::vector<int> graph[102];
int cnts[102];
void DFS(int cur)
{
    cnts[cur] = 1;
    for(const auto& iter : graph[cur])
    {
        if(cnts[iter]) continue;
        DFS(iter);
        cnts[cur] += cnts[iter];
    }
}
int solution(int n, vector<vector<int>> wires) 
{
    int answer = 100;
    for(const auto& iter : wires)
    {
        graph[iter[0]].push_back(iter[1]);
        graph[iter[1]].push_back(iter[0]);
    }
    DFS(1);

    for(int i = 1; i <= n; i++)
    {
        //std::cout << cnts[i] << '\n';
        answer = std::min(answer, std::abs(cnts[i] * 2 - n));
    }
    
    return answer;
}