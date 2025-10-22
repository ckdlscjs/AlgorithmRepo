#include <bits/stdc++.h>
using namespace std;
std::queue<int> q;
int dist[1'000'002];
int solution(int x, int y, int n) 
{
    int answer = 0;
    dist[y] = 1;
    q.push(y);
    while(q.size())
    {
        auto cur = q.front();
        q.pop();
        if(cur % 2 == 0 && dist[cur/2] == 0)
        {
            dist[cur/2] = dist[cur] + 1;
            q.push(cur/2);
        }
        if(cur % 3 == 0 && dist[cur/3] == 0)
        {
            dist[cur/3] = dist[cur] + 1;
            q.push(cur/3);
        }
        if(cur - n >= 1 && dist[cur-n] == 0)
        {
            dist[cur-n] = dist[cur]+1;
            q.push(cur-n);
        }
    }
    return dist[x] - 1;
}