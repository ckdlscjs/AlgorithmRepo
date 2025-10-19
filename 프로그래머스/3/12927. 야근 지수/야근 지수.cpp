#include <bits/stdc++.h>
using namespace std;
std::priority_queue<int, std::vector<int>, std::less<int>> pq;
long long solution(int n, vector<int> works) 
{
    for(const auto& iter : works)
        pq.push(iter);
    while(n && pq.size())
    {
        int cur = pq.top();
        pq.pop();
        if(cur >= 1)
            pq.push(cur-1);
        n--;
    }
    long long answer = 0;
    while(pq.size())
        answer += pq.top() * pq.top(), pq.pop();
    
    return answer;
}