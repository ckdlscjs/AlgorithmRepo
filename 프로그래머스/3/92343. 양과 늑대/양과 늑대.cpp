#include <bits/stdc++.h>

using namespace std;

std::vector<std::vector<int>> node;
int Check(const std::vector<int>& info, int sheep, int wolf, std::vector<bool>& visited, std::vector<int> routes)
{
    auto ret = sheep;
    if(ret <= wolf) return ret;
    for(const auto& nextnode : routes)
    {
        for(const auto& next : node[nextnode])
        {
            if(visited[next]) continue;
            auto n_routes = routes;
            visited[next] = true;
            n_routes.push_back(next);
            auto temp = Check(info, sheep + (info[next] ? 0 : 1), wolf + (info[next] ? 1 : 0), visited, n_routes);
            visited[next] = false;
            ret = std::max(ret, temp);
        }
    }
    return ret;
}
int solution(vector<int> info, vector<vector<int>> edges) 
{
    std::vector<bool> visited(info.size(), false);
    node.resize(info.size(), std::vector<int>());
    for(const auto& iter : edges)
    {
        node[iter[0]].push_back(iter[1]);
        node[iter[1]].push_back(iter[0]);
    }
    visited[0] = true;
    return Check(info, 1, 0, visited, {0});
}