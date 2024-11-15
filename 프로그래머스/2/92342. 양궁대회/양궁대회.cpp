#include <bits/stdc++.h>
using namespace std;
int res = 0;
std::vector<int> res_ans;
struct compare
{
    bool operator()(const std::pair<int, std::vector<int>>& a, const std::pair<int, std::vector<int>>& b)
    {
        if(a.first == b.first)
        {
            for(int i = 0; i < a.second.size(); i++)
            {
                if(a.second[10-i] == b.second[10-i])
                    continue;
                return a.second[10-i] < b.second[10-i];
            }
        }
        return a.first < b.first;
    }
};
std::priority_queue<std::pair<int, std::vector<int>>, std::vector<std::pair<int, std::vector<int>>>, compare> pq;
void Check(const int& n, const vector<int>& info, int cnt, int idx, std::vector<int>& ans)
{
    if(idx >= ans.size())
    {
        if(cnt != n) return;
        int sum_l = 0, sum_a = 0;
        for(int i = 0; i < ans.size(); i++)
        {
            if(ans[i] == 0 && info[i] == 0) continue;
            if(ans[i] <= info[i]) sum_a += 10-i;
            else if(ans[i] > info[i]) sum_l += 10-i;
        }
        if(sum_l > sum_a)
            pq.push({sum_l-sum_a, ans});
        return;
    }
    for(int j = n-cnt; j >= 0; j--)
    {
        ans[idx] = j;
        Check(n, info, cnt+j, idx+1, ans);
        ans[idx] = 0;
    }
}
vector<int> solution(int n, vector<int> info) 
{
    std::vector<int> answer(11, 0);
    pq.push({-1, {-1}});
    Check(n, info, 0, 0, answer);

    return pq.top().second;
}