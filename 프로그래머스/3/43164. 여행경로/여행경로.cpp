#include <bits/stdc++.h>
using namespace std;
const int MaxN = 10005;
unordered_map<string, int> idxs;
vector<pair<string, bool>> graph[MaxN];

void dfs(vector<string>& ans, string cur) 
{
    while (!graph[idxs[cur]].empty()) 
    {
        auto next = graph[idxs[cur]].front();
        graph[idxs[cur]].erase(graph[idxs[cur]].begin());
        dfs(ans, next.first);
    }
    ans.push_back(cur);
}

vector<string> solution(vector<vector<string>> tickets) 
{
    set<string> inputs;
    for (const auto& iter : tickets) 
    {
        inputs.insert(iter[0]);
        inputs.insert(iter[1]);
    }
    
    int cnt = 0;
    for (const auto& iter : inputs)
        idxs[iter] = cnt++;
    
    for (const auto& iter : tickets)
        graph[idxs[iter[0]]].push_back({iter[1], false});
    
    for (int i = 0; i < idxs.size(); i++)
        sort(graph[i].begin(), graph[i].end(), std::less<>());

    vector<string> answer;
    dfs(answer, "ICN");
    reverse(answer.begin(), answer.end());  // 역순으로 경로가 쌓이므로 역으로 뒤집어 줍니다.
    
    return answer;
}
