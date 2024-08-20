#include <bits/stdc++.h>
using namespace std;
struct compare
{
    bool operator()(const std::pair<int, std::vector<int>>& a, const std::pair<int, std::vector<int>>& b)
    {
        if(a.first != b.first)
        {
            return a.first < b.first;
        }
        else
        {
            for(int i = 0; i < a.second.size(); i++)
            {
                if(a.second[10-i] == b.second[10-i])
                    continue;
                return a.second[10-i] < b.second[10-i];
            }
        }
    }
};
std::priority_queue<std::pair<int, std::vector<int>>, std::vector<std::pair<int, std::vector<int>>>, compare> pq;
void check(const std::vector<int>& info_appeach, int cnt, int idx, std::vector<int>& info_lion)
{
    if(idx >= info_appeach.size())
    {
        if(cnt != 0)
            return;
        int sum_appeach = 0;
        int sum_lion = 0;
        for(int i = 0; i < info_lion.size(); i++)
        {
            if(info_lion[i] == info_appeach[i] && info_lion[i] == 0)
                continue;
            if(info_lion[i] > info_appeach[i])
                sum_lion += 10-i;
            else
                sum_appeach += 10-i;
        }
        if(sum_lion > sum_appeach)
            pq.push({sum_lion - sum_appeach, info_lion});
    }
    else
    {
        for(int shot = 0; shot <= cnt; shot++)
        {
            info_lion[idx] = shot;
            check(info_appeach, cnt - shot, idx+1, info_lion);
            info_lion[idx] = 0;
        }
    }
}
vector<int> solution(int n, vector<int> info) 
{
    pq.push({-1, {-1}});
    std::vector<int> lion = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    check(info, n, 0, lion);
    return pq.top().second;
}