#include <bits/stdc++.h>

std::unordered_map<int, int> dist;
int solution(int n)
{
    std::deque<int> dq;
    dist[n] = 0;
    dq.push_back(n);
    while(1)
    {
        auto cur = dq.front();
        dq.pop_front();
        if(cur <= 0) break;
        if(cur % 2 == 0 && dist.find(cur / 2) == dist.end())
        {
            dq.push_front(cur/2);
            dist[cur/2] = dist[cur];
        }
        else
        {
            dq.push_back(cur-1);
            dist[cur-1] = dist[cur] + 1;
        }
    }
    return dist[0];
}