//https://school.programmers.co.kr/learn/courses/30/lessons/60062
#include <bits/stdc++.h>
using namespace std;
int solution(int n, vector<int> weak, vector<int> dist) 
{
    std::vector<int> weaks = weak;
    for(const auto& iter : weak)
        weaks.push_back(iter + n);
    int res = dist.size() + 1;
    do
    {
        for(int i = 0; i < weaks.size()/2; i++)
        {
            int cnt = 0;
            int pos = weaks[i] + dist[cnt];
            for(int j = i+1; j < i + weaks.size()/2; j++)
            {
                if(pos < weaks[j])
                {
                    cnt++;
                    if(cnt >= dist.size())
                        break;
                    pos = weaks[j] + dist[cnt];
                }
            }
            res = std::min(res, cnt+1);
        }
    }while(next_permutation(dist.begin(), dist.end()));
    return res > dist.size()? -1 : res;
}