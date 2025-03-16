#include <bits/stdc++.h>
using namespace std;
//1'000'000'000'000'000 10^15
long long int Check(const long long int num, int idx, int curidx, long long int cur)
{
    if(idx >= 2) return (cur > num ? cur : (long long int)1e16);
    long long int ret = (long long int)1e16;
    if(idx >= 1 && cur > num)
        ret = std::min(ret, cur);
    for(long long int i = curidx; i < 63; i++)
        ret = std::min(ret, Check(num, idx+1, i+1, cur ^ (1LL << i)));
    return ret;
}
vector<long long> solution(vector<long long> numbers) 
{
    vector<long long> answer;
    for(const auto& iter : numbers)
    {
        answer.push_back(Check(iter, 0, 0, iter));
    }
    return answer;
}