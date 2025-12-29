#include <bits/stdc++.h>
using namespace std;
int Check(const int n, const std::vector<std::vector<int>>& q, const std::vector<int>& ans, int mask, int idx, int cur)
{
    if(cur >= 5)
    {
        for(int i = 0; i < q.size(); i++)
        {
            int cnt = 0;
            for(const auto& c : q[i])
                if(mask & (1 << c))
                    cnt++;
            if(cnt != ans[i])
                return 0;
        }
        return 1;
    }
    if(idx > n) return 0;
    int ret = 0;
    for(int i = idx; i <= n; i++)
    {
        ret += Check(n, q, ans, mask | 1 << i, i+1, cur+1);
    }
    return ret;
}
int solution(int n, vector<vector<int>> q, vector<int> ans) 
{
    return Check(n, q, ans, 0, 1, 0);
}