#include <bits/stdc++.h>
using namespace std;
struct comp
{
    bool operator()(const std::pair<int, std::vector<int>>& a, const std::pair<int, std::vector<int>>& b)
    {
        if(a.first == b.first)
        {
            for(int i = a.second.size()-1; i >= 0; i--)
            {
                if(a.second[i] == b.second[i]) continue;
                return a.second[i] < b.second[i];
            }
        }
        return a.first < b.first;
    }
};
std::priority_queue<std::pair<int, std::vector<int>>, std::vector<std::pair<int, std::vector<int>>>, comp> pq;
void DFS(const int& n, const std::vector<int>& info, int idx, int cnt, std::vector<int>& ans)
{
    if(idx >= info.size())
    {
        if(n != cnt) return;
        int sum_ryan = 0, sum_appeach = 0;
        for(int i = 0; i < idx; i++)
        {
            if(ans[i] == 0 && info[i] == 0) continue;
            if(ans[i] <= info[i]) sum_appeach += 10-i;
            else sum_ryan += 10-i;
        }
        if(sum_ryan > sum_appeach)
            pq.push({sum_ryan-sum_appeach, ans});
        return;
    }
    DFS(n, info, idx+1, cnt, ans);
    if(n-cnt > info[idx])
    {
        ans[idx] = info[idx]+1;
        DFS(n, info, idx+1, cnt + ans[idx], ans);
        ans[idx] = 0;
    }
    else
    {
        ans[idx] = n-cnt;
        DFS(n, info, idx+1, cnt + ans[idx], ans);
        ans[idx] = 0;
    }
}
vector<int> solution(int n, vector<int> info) 
{
    pq.push({-1, {-1}});
    vector<int> answer(11, 0);
    DFS(n, info, 0, 0, answer);
    return pq.top().second;
}