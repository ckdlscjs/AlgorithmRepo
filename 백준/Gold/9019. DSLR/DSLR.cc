#include <bits/stdc++.h>
int T, A, B;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    for(int t = 0; t < T; t++)
    {
        std::vector<int> dp(10'005, 0);
        std::vector<std::string> dp_str(10'005);
        std::cin >> A >> B;
        std::queue<int> q;
        dp[A] = 1;
        q.push(A);
        while(q.size())
        {
            int cur = q.front();
            q.pop();
            
            int D = cur*2;
            D %= 10'000;
            if(!dp[D])
            {
                dp[D] = dp[cur] + 1;
                dp_str[D] = dp_str[cur] + "D";
                q.push(D);
            }
            
            int S = cur-1;
            if(S < 0) S = 9999;
            if(!dp[S])
            {
                dp[S] = dp[cur] + 1;
                dp_str[S] = dp_str[cur] + "S";
                q.push(S);
            }
            
            int L = (cur % 1000) * 10 + cur / 1000;
            if(!dp[L])
            {
                dp[L] = dp[cur] + 1;
                dp_str[L] = dp_str[cur] + "L";
                q.push(L);
            }
            
            int R = (cur % 10) * 1000 + (cur / 10);
            if (!dp[R])
            {
                dp[R] = dp[cur] + 1;
                dp_str[R] = dp_str[cur] + "R";
                q.push(R);
            }
        }
        std::cout << dp_str[B] << '\n';
    }
	return 0;
}