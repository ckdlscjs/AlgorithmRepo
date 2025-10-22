#include <bits/stdc++.h>

using namespace std;
int dp[100'002], cnts[100'002];
std::vector<int> sb = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
vector<int> solution(int target) 
{
    std::fill_n(&dp[1], 100'002, 100'000);
    for(int i = 0; i < sb.size(); i++)
    {
        dp[sb[i]] = 1;
        cnts[sb[i]] = 1;
    }
    dp[50] = 1;
    cnts[50] = 1;
    for(int i = 21; i <= target; i++)
    {
        if(i - 50 >= 0 && dp[i-50] + 1 <= dp[i])
        {
            dp[i] = dp[i-50] + 1;
            cnts[i] = std::max(cnts[i], cnts[i-50] + 1);
        }
        for(const auto& iter : sb)
        {
            if(i - iter >= 0 && dp[i-iter] + 1 <= dp[i])
            {
                dp[i] = dp[i-iter] + 1;
                cnts[i] = std::max(cnts[i], cnts[i-iter] + 1);
            }
            if(i - iter * 2 >= 0 && dp[i-iter*2] + 1 < dp[i])
            {
                dp[i] = dp[i-iter*2] + 1;
                cnts[i] = 0;
            }
            if(i - iter * 3 >= 0 && dp[i-iter*3] + 1 < dp[i])
            {
                dp[i] = dp[i-iter*3] + 1;
                cnts[i] = 0;
            }
        }
    }
    return {dp[target], cnts[target]};
}