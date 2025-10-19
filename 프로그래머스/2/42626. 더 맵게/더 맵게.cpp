#include <bits/stdc++.h>

using namespace std;
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
int solution(vector<int> scoville, int K) 
{
    for(const auto& iter : scoville)
        pq.push(iter);
        
    
    int answer = 0;
    while(pq.size() >= 2 && pq.top() < K)
    {
        auto sco0 = pq.top(); pq.pop();
        auto sco1 = pq.top(); pq.pop();
        pq.push(sco0 + sco1 * 2);
        answer++;
    }
    
    return pq.top() >= K ? answer : -1;
}