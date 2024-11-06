//https://school.programmers.co.kr/learn/courses/30/lessons/92343
#include <bits/stdc++.h>
using namespace std;
std::vector<int> graph[20];
int Check(const std::vector<int>& infos, int sheep, int wolf, std::unordered_set<int> paths)
{
    if(sheep <= wolf)
        return sheep;
    int ret = sheep;
    for(const auto& iter : paths)
    {
        for(const auto& next : graph[iter])
        {
            if(paths.find(next) != paths.end()) continue;
            std::unordered_set<int> newpath = paths;
            newpath.insert(next);
            ret = std::max(ret, Check(infos, sheep + (infos[next] ? 0 : 1), wolf + (infos[next] ? 1 : 0), newpath));
        }
    }
    return ret;
}
int solution(vector<int> info, vector<vector<int>> edges) 
{
    for(const auto& iter : edges)
    {
        graph[iter[0]].push_back(iter[1]);
        graph[iter[1]].push_back(iter[0]);
    }  
    return Check(info, 1, 0, {0});
}