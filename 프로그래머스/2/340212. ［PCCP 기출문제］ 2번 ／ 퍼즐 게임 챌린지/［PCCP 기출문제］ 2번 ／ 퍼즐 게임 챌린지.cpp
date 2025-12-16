#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) 
{
    int lo = 0, hi = 100'000;
    while(lo + 1 < hi)
    {
        int level = (lo + hi) / 2;
        long long cur = 0;
        int prev = 0;
        for(int i = 0; i < diffs.size(); i++)
        {
            if(level < diffs[i])
                cur += (diffs[i] - level) * (times[i] + prev);
            cur += times[i];
            prev = times[i];
        }
        if(cur <= limit) hi = level;
        else lo = level;
    }
    return hi;
}