#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> priorities, int location) 
{
    std::priority_queue<int, std::vector<int>, std::less<int>> pq;
    std::deque<std::pair<int, int>> dq;
    for(int i = 0; i < priorities.size(); i++)
    {
        pq.push(priorities[i]);
        dq.push_back({priorities[i], i});
    }
    int i = 1;
    while(dq.size())
    {
        if(pq.top() == dq.front().first)
        {
            int idx = dq.front().second;
            dq.pop_front();
            pq.pop();
            if(idx == location) return i;
            i++;
        }
        else
        {
            dq.push_back(dq.front());
            dq.pop_front();
        }
    }
    return 0;
}