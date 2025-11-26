#include <bits/stdc++.h>
using namespace std;
std::map<std::string, std::vector<std::pair<std::string, bool>>> graph;
bool DFS(const int& cnt, vector<string>& answer, const std::string& cur)
{
    if(answer.size() > cnt) return true;
    for(auto& iter : graph[cur])
    {
        if(iter.second) continue;
        iter.second = true;
        answer.push_back(iter.first);
        bool res = DFS(cnt, answer, iter.first);
        if(res) return true;
        answer.pop_back();
        iter.second = false;
    }
    return false;
}
vector<string> solution(vector<vector<string>> tickets) 
{
    for(const auto& iter : tickets) graph[iter[0]].push_back({iter[1], false});
    for(auto& iter : graph) std::sort(iter.second.begin(), iter.second.end());  
    std::vector<std::string> answer;
    answer.push_back("ICN");
    DFS(tickets.size(), answer, "ICN");
    return answer;
}