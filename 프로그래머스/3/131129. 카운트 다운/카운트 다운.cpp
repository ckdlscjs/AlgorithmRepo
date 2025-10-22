#include <bits/stdc++.h>

using namespace std;
int dp[100'052], cnts[100'052];
std::queue<std::tuple<int, int, int, int, int>> q;
vector<int> solution(int target) 
{
    q.push({0, 0, 0, 0, 0});
    while(q.size())
    {
        auto cur = q.front();
        q.pop();
        int cc = std::get<0>(cur);
        int cs = std::get<1>(cur);
        int cd = std::get<2>(cur);
        int ct = std::get<3>(cur);
        int cb = std::get<4>(cur);
        /*
        if(cc == target)
        {
            std::cout << cc;
            std::cout << cs << ' ' << cd <<' ' << ct <<' ' << cb<< '\n';
        }
        */
        if(cc + 50 <= 100'000)
        {
            if(dp[cc + 50] == 0)
            {
                q.push({cc+50, cs, cd, ct, cb+1});
                dp[cc + 50] = dp[cc]+1;
            }
            if(dp[cc + 50] == dp[cc] + 1)
                cnts[cc+50] = std::max(cnts[cc+50], cs+cb+1);
        }
        for(int i = 1; i <= 20; i++)
        {
            if(cc + i <= 100'000)
            {
                if(dp[cc+i] == 0)
                {
                    q.push({cc+i, cs+1, cd, ct, cb});
                    dp[cc+i] = dp[cc]+1;
                }
                if(dp[cc+i] == dp[cc] + 1)
                    cnts[cc+i] = std::max(cnts[cc+i], cs+1+cb);
            }
        }
        for(int i = 1; i <= 20; i++)
        {
            if(cc + i*2 <= 100'000)
            {
                if(dp[cc+i*2] == 0)
                {
                    q.push({cc+i*2, cs, cd+1, ct, cb});
                    dp[cc+i*2] = dp[cc] + 1;
                }
                if(dp[cc+i*2] == dp[cc] + 1)
                    cnts[cc+i*2] = std::max(cnts[cc+i*2], cs+cb);
            }
        }    
        for(int i = 1; i <= 20; i++)
        {
            if(cc + i*3 <= 100'000)
            {
                if(dp[cc+i*3] == 0)
                {
                    q.push({cc+i*3, cs, cd, ct+1, cb});
                    dp[cc+i*3] = dp[cc] + 1;
                }
                if(dp[cc+i*3] == dp[cc] + 1)
                    cnts[cc+i*3] = std::max(cnts[cc+i*3], cs+cb);
            }
        }
    }
    return {dp[target], cnts[target]};
}