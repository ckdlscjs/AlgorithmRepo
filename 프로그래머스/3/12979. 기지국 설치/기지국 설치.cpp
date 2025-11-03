#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    stations.push_back(n+w+1);
    int cur = 0;
    int cnt = 0;
    int r = w * 2 + 1;
    for(int i = 0; i < stations.size(); i++)
    {
        if(cur < stations[i] - w)
        {
            int diff = (stations[i] - w - cur - 1);
            cnt += diff/r + (diff%r ? 1 : 0);
            cur = stations[i] + w;
        }
        cur = std::max(stations[i] + w, cur);
    }
    
    return cnt;
}