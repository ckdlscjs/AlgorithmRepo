#include <bits/stdc++.h>
using namespace std;
std::vector<int> graph[1'000'005];
int enters[1'000'005];
bool visited[1'000'005];
std::pair<int, int> check(int cur)
{
    std::pair<int, int> ret = {1, 0};
    visited[cur] = true;
    for(const auto& iter : graph[cur])
    {
        ret.second++;
        if(visited[iter]) continue;
        auto r = check(iter);
        ret.first += r.first;
        ret.second += r.second;
    }
    return ret;
}
vector<int> solution(vector<vector<int>> edges) 
{
    vector<int> answer(4, 0);
    int cnt = 0, vertex = 0; 
    for(const auto& iter : edges)
    {
        graph[iter[0]].push_back(iter[1]);
        enters[iter[1]]++;
        if(graph[iter[0]].size() >= cnt && enters[iter[0]] == 0)
        {
            vertex = iter[0];
            cnt = graph[iter[0]].size();
        } 
    }
    answer[0] = vertex;
    for(const auto& iter : graph[vertex])
    {
        std::pair<int, int> ret = check(iter);
        if(ret.first < ret.second)
            answer[3]++;
        else if(ret.first == ret.second)
            answer[1]++;
        else if(ret.first > ret.second)
            answer[2]++;
    }

    return answer;
}