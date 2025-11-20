#include <bits/stdc++.h>

using namespace std;

int solution(int n, int k, vector<int> enemy)
{
    int lo = -1, hi = enemy.size() + 1;
    while(lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;
        std::vector<int> temp(enemy.begin(), enemy.begin() + mid);
        std::sort(temp.begin(), temp.end(), std::greater<>());
        int cn = n;
        int ck = k;
        int idx = 0;
        for(idx; idx < temp.size(); idx++)
        {
            if(ck > 0)
            {
                ck--;
                continue;
            }
            cn -= temp[idx];
            if(cn < 0) 
                break;
        }
        if(idx >= temp.size()) lo = mid;
        else hi = mid;
    }
    return lo;
}