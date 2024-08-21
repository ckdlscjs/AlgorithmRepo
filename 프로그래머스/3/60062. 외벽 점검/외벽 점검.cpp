#include <bits/stdc++.h>
using namespace std;
int result;
int length;
std::vector<int> weaks;
std::vector<int> dists;
bool friends[10];
void check(std::vector<int> dist_per)
{
    if(dist_per.size() >= dists.size())
    {
        for(int i = 0; i < length; i++)
        {
            int cnt = 1;
            int pos = weaks[i] + dist_per[cnt-1];
            for(int j = i; j < i + length; j++)
            {
                if(pos < weaks[j])
                {
                    cnt++;
                    if(cnt > dist_per.size())
                        break;
                    pos = weaks[j] + dist_per[cnt-1];
                }  
            }
            result = std::min(result, cnt);
        }
    }
    else
    {
        for(int i = 0; i < dists.size(); i++)
        {
            if(friends[i])
                continue;
            friends[i] = true;
            dist_per.push_back(dists[i]);
            check(dist_per);
            friends[i] = false;
            dist_per.pop_back();
        }
    }
}

int solution(int n, vector<int> weak, vector<int> dist) 
{
    std::sort(dist.begin(), dist.end(), std::greater<>());
    result = dist.size() + 1;
    length = weak.size();
    for(int i = 0; i < length; i++)
        weak.push_back(weak[i] + n);
    weaks = weak;
    dists = dist;
    check({});
    return result >= dists.size()+1 ? -1 : result;
}