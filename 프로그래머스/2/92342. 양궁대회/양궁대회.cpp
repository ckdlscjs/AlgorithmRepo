#include <bits/stdc++.h>
using namespace std;
int res = 0;
std::vector<int> res_ans;
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
        if(res < sum_l - sum_a)
        {
            res = sum_l-sum_a;
            res_ans = ans;
        }
        else if (res != 0 && res == sum_l - sum_a)
        {
            for (int i = ans.size() - 1; i >= 0; i--)
            {
                if (ans[i] < res_ans[i]) break; 
                if (ans[i] > res_ans[i])
                {
                    res_ans = ans;
                    break;
                }
            }
        }
        return;
    }
    for(int j = 0; j <= n - cnt; j++)
    {
        ans[idx] = j;
        Check(n, info, cnt+j, idx+1, ans);
        ans[idx] = 0;
    }
}
vector<int> solution(int n, vector<int> info) 
{
    std::vector<int> answer(11, 0);
    Check(n, info, 0, 0, answer);
    if(res == 0 || res_ans.empty())
        return {-1};
    return res_ans;
}