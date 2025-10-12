#include <bits/stdc++.h>
using namespace std;
int Check(const std::vector<std::vector<int>> dungeons, int k, int cnt, int mask)
{
    if(cnt >= dungeons.size())
    {
        return dungeons.size();
    }
    else
    {
        int ret = cnt;
        for(int i = 0; i < dungeons.size(); i++)
        {
            if(mask & (1 << i)) continue;
            int need = dungeons[i][0];
            int used = dungeons[i][1];
            if(need > k) continue;
            ret = std::max(ret, Check(dungeons, k-used, cnt+1, mask | (1 << i)));
        }
        return ret;
    }
}
int solution(int k, vector<vector<int>> dungeons) 
{
    return Check(dungeons, k, 0, 0);
}