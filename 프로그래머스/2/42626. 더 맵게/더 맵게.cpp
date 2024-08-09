#include <bits/stdc++.h>
using namespace std;
std::priority_queue<int, std::vector<int>, std::greater<>> pq;
int solution(vector<int> scoville, int K) 
{
    for(const auto& iter : scoville)
        pq.push(iter);
    int cur = pq.top();
    pq.pop();
    int answer = 0;
    if(cur >= K)
        return answer;
    while(pq.size())
    {
        int top = pq.top();
        pq.pop();
        int min1 = std::min(cur, top);
        int min2 = std::max(cur, top);
        cur = min1 + (min2 * 2);
        pq.push(cur);
        cur = pq.top();
        pq.pop();
        answer++;
        if(pq.size() && pq.top() >= K && cur >= K)
            break;
    }
    if(cur < K)
        return -1;
    return answer;
}