#include <bits/stdc++.h>

using namespace std;

long long solution(int k, int d) 
{
    long long _k = k, _d = d;
    long long answer = 0;
    for(long long x = 0; x <= d; x += k)
    {
        answer += (long long)std::sqrt(_d * _d - x * x) / _k + 1LL;
    }
    return answer;
}