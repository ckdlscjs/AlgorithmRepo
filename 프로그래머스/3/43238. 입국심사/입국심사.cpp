//https://school.programmers.co.kr/learn/courses/30/lessons/43238
#include <bits/stdc++.h>
using namespace std;
bool Check(int n, const vector<int>& times, long long int t)
{
    long long int cnt = 0;
    for(const auto& iter : times)
        cnt += t / (long long int)iter;
    return cnt >= n;
}
long long solution(int n, vector<int> times) 
{
    long long int lo = 0, hi = 1'000'000'000'000'005;
    while(lo + 1 < hi)
    {
        long long int mid = (lo + hi) / 2;
        if(Check(n, times, mid)) hi = mid;
        else lo = mid;
    }
    return hi;
}