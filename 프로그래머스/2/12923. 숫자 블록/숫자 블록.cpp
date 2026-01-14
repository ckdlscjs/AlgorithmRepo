#include <bits/stdc++.h>

using namespace std;
const int maxDivisor = 1e7;
vector<int> solution(long long begin, long long end) 
{
    vector<int> answer;
    for(begin; begin <= end; begin++)
    {
        if(begin == 1)
        {
            answer.push_back(0);
            continue;
        }
        int res = 1;
        for(int i = 2; i <= std::sqrt(begin); i++)
        {
            if(begin % i == 0)
            {
                res = std::max(res, i);
                if(begin / i <= maxDivisor)
                {
                    res = begin / i;
                    break;
                }  
            }
        }
        answer.push_back(res);
    }
    return answer;
}