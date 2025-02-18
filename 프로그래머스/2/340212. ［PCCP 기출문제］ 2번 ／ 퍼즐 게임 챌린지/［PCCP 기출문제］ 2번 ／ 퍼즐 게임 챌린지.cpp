#include <bits/stdc++.h>

using namespace std;

long long int solution(vector<int> diffs, vector<int> times, long long limit) 
{
    long long int lo = 0, hi = *std::max_element(diffs.begin(), diffs.end()) + 1;
    while(lo + 1 < hi)
    {
        long long int mid = (lo + hi) / 2;
        long long int cur = 0;
        for(int i = 0; i < diffs.size(); i++)
        {
            if(diffs[i] <= mid)
                cur += times[i];
            else
                cur += (diffs[i]-mid)*(times[i] + (i > 0 ? times[i-1] : 0)) + times[i];
        }
        if(cur <= limit) hi = mid;
        else lo = mid;
    }
    
    return hi;
}