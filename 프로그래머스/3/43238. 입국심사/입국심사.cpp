#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solution(int n, vector<int> times) 
{
    ll lo = 0, hi = 1e9 * 1e9 + 5LL;
    while(lo + 1 < hi)
    {
        ll mid = (lo + hi) / 2;
        ll c = 0;
        for(const auto& t : times)
            c += mid / (long long)t;
        if(n <= c) hi = mid;
        else lo = mid;
    }
    return hi;
}