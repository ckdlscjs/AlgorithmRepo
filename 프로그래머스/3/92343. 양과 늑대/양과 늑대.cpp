#include <bits/stdc++.h>
const int MaxN = 20;
using namespace std;
struct state
{
    int idx;
    int sheep;
    int wolf;
    std::unordered_set<int> way;
};
int solution(vector<int> info, vector<vector<int>> edges) 
{
    std::vector<int> graph[MaxN];
    for(const auto& iter : edges)
        graph[iter[0]].push_back(iter[1]);
    std::queue<state> q;
    q.push({0, 1, 0, {0}});
    int answer = 0;
    while(q.size())
    {
        state s = q.front();
        q.pop();
        answer = std::max(answer, s.sheep);
        if(s.wolf >= s.sheep)
            continue;
        for(const auto& iter : s.way)
        {
            for(int i = 0; i < graph[iter].size(); i++)
            {
                if(s.way.find(graph[iter][i]) != s.way.end())
                    continue;
                int newsheep = s.sheep + (!info[graph[iter][i]] ? 1 : 0);
                int newwolf = s.wolf + (!info[graph[iter][i]] ? 0 : 1);
                std::unordered_set<int> newway = s.way;
                newway.insert(graph[iter][i]);
                q.push({info[graph[iter][i]], newsheep, newwolf, newway});
            }
        }
    }
    
    return answer;
}