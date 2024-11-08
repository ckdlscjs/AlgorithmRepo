//https://school.programmers.co.kr/learn/courses/30/lessons/43164
#include <bits/stdc++.h>
using namespace std;
std::unordered_map<std::string, std::vector<std::pair<std::string, bool>>> graph;
bool Check(const int counts, std::vector<std::string>& ans, std::string cur)
{
    ans.push_back(cur);
    if(ans.size() > counts) return true;
    for(auto& it : graph[cur])
    {
        if(it.second) continue;
        it.second = true;
        if(Check(counts, ans, it.first)) return true;
        it.second = false;
    }
    ans.pop_back();
    return false;
}
vector<string> solution(vector<vector<string>> tickets) 
{
    for(const auto& iter : tickets) graph[iter[0]].push_back({iter[1], false});
    for(auto& it : graph)
        std::sort(it.second.begin(), it.second.end(), std::less<>());
    std::vector<std::string> answer;
    Check(tickets.size(), answer, "ICN");
    return answer;
}