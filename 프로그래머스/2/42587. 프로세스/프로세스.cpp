#include <bits/stdc++.h>
using namespace std;
std::queue<std::pair<int, int>> q;
std::priority_queue<int, std::vector<int>, std::less<>> pq;
int solution(vector<int> priorities, int location) 
{
    for(int i = 0; i < priorities.size(); i++)
    {
        pq.push(priorities[i]);
        q.push({priorities[i], i});
    }
    int count = 0;
    int answer = 0;
    while(pq.size())
    {
        std::pair<int, int> iter = q.front();
        q.pop();
        if(pq.top() == iter.first)
        {
            pq.pop();
            count++;
            if(iter.second == location)
                answer = count;
        }
        else
        {
            q.push(iter);
        }
    }
    return answer;
}