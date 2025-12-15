#include <bits/stdc++.h>

using namespace std;
std::unordered_map<std::string, int> pick;
const int cost[3][3] = 
{
    {1, 1, 1},
    {5, 1, 1},
    {25, 5, 1}
};
int Check(std::vector<int>& picks, const std::vector<std::string>& minerals, int cnt, int idx)
{
    if(idx >= minerals.size() || cnt <= 0) return 0;
    int ret = 25 * 55;
    for(int i = 0; i < 3; i++)
    {
        if(picks[i] <= 0) continue;
        picks[i] -= 1;
        int amount = 0;
        for(int j = 0; j < 5 && idx + j < minerals.size(); j++)
            amount += cost[i][pick[minerals[idx+j]]];
        ret = std::min(ret, Check(picks, minerals, cnt - 1, idx+5) + amount);
        picks[i] += 1;
    }
    return ret;
}
int solution(vector<int> picks, vector<string> minerals) 
{
    pick["diamond"] = 0;
    pick["iron"] = 1;
    pick["stone"] = 2;
    int cnt = 0;
    for(const auto& iter : picks)
        cnt += iter;
    return Check(picks, minerals, cnt, 0);
}