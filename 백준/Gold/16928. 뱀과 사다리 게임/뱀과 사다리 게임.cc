#include <bits/stdc++.h>
int N, M, dp[102], sl[102], u, v;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for(int i = 0; i < N + M; i++)
    {
        std::cin >> u >> v;
        sl[u] = v;
    }
    dp[1] = 1;
    std::queue<int> q;
    q.push(1);
    while(q.size())
    {
        int cur = q.front();
        q.pop();
        for(int i = 1; i <= 6; i++)
        {
            int nxt = cur + i;
            if(nxt > 100) continue;
            while(sl[nxt])
                nxt = sl[nxt];
            if(dp[nxt]) continue;
            dp[nxt] = dp[cur] + 1;
            q.push(nxt);
        }
    }
    std::cout << dp[100] - 1;
	return 0;
}