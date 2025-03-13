#include <bits/stdc++.h>
using namespace std;
int dp[1'000'005];
int solution(int x, int y, int n) 
{
    std::queue<int> q;
    q.push(x);
    dp[x] = 1;
    while(q.size())
    {
        int cur = q.front();
        q.pop();
        for(const auto& iter : {cur + n, cur * 2, cur * 3})
        {
            if(1'000'000 < iter) continue;
            if(dp[iter]) continue;
            dp[iter] = dp[cur] + 1;
            q.push(iter);
        }
    }
    return (dp[y] ? dp[y]-1 : -1);
}