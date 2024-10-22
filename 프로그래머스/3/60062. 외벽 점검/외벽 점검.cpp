//https://school.programmers.co.kr/learn/courses/30/lessons/60062
#include <bits/stdc++.h>
using namespace std;
int res;
void Check(const std::vector<int>& weaks, const std::vector<int>& dists, std::vector<int> friends, int uses)
{
    if(friends.size() >= dists.size())
    {
        for(int i = 0; i < weaks.size()/2; i++)
        {
            int cnt = 0;
            int pos = weaks[i] + friends[cnt];
            for(int j = i; j < i + weaks.size()/2; j++)
            {
                if(pos < weaks[j])
                {
                    cnt++;
                    if(cnt >= friends.size())
                        break;
                    pos = weaks[j] + friends[cnt];
                }
            }
            res = std::min(res, cnt+1);
        }
    }
    else
    {
        for(int i = 0; i < dists.size(); i++)
        {
            if(uses & 1 << i)
                continue;
            friends.push_back(dists[i]);
            Check(weaks, dists, friends, uses | 1 << i);
            friends.pop_back();
        }
    }
}
int solution(int n, vector<int> weak, vector<int> dist) 
{
    std::vector<int> weaks = weak;
    for(const auto& iter : weak)
        weaks.push_back(iter + n);
    res = dist.size() + 1;
    Check(weaks, dist, {}, 0);
    return res >= dist.size() + 1? -1 : res;
}