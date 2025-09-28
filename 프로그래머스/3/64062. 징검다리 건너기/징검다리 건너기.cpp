#include <bits/stdc++.h>

using namespace std;
bool Check(const std::vector<int>& stones, const int& k, const int& height)
{
    int cnt = 0;
    for(const auto& iter : stones)
    {
        if(iter > height) cnt = 0;
        else cnt++;
        if(cnt >= k) return false;
    }
    return true;
}
int solution(vector<int> stones, int k) 
{
    int lo = 0, hi = 200'000'001;
    while(lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;
        if(Check(stones, k, mid)) lo = mid;
        else hi = mid;
    }
    return hi;
}