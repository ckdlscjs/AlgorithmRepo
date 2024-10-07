//https://school.programmers.co.kr/learn/courses/30/lessons/131128
#include <bits/stdc++.h>
using namespace std;
long long int cntX[15];
long long int cntY[15];
string solution(string X, string Y) 
{
    std::string ans = "";
    for(const auto& ch : X)
        cntX[ch-'0']++;
    for(const auto& ch : Y)
        cntY[ch-'0']++;
    bool isZero = false;
    for(int i = 9; i >= 0; i--)
    {
        if(cntX[i] && cntY[i])
        {
            int mincnt = std::min(cntX[i], cntY[i]);
            for(int j = 0; j < mincnt; j++)
            {
                if(i == 0 && ans.empty())
                    isZero = true;
                ans += std::to_string(i);
            }
        }
    }
    
    return ans.size() ? isZero ? "0" : ans : "-1";
}