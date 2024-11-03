//https://school.programmers.co.kr/learn/courses/30/lessons/12927
#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> works) 
{
    std::priority_queue<long long int, std::vector<long long int>, std::less<long long int>> pq;
    for(const auto& iter : works)
        pq.push(iter);
    while(n-- && pq.size())
    {
        long long int cur = pq.top();
        pq.pop();
        cur--;
        if(cur)
            pq.push(cur);
    }
    long long answer = 0;
    while(pq.size())
        answer += std::pow(pq.top(), 2), pq.pop();
    
    return answer;
}