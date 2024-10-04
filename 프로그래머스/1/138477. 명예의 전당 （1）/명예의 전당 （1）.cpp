//https://school.programmers.co.kr/learn/courses/30/lessons/138477
#include <bits/stdc++.h>
using namespace std;
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
vector<int> solution(int k, vector<int> score) 
{
    vector<int> answer;
    for(const auto& iter : score)
    {
        pq.push(iter);
        if(pq.size() > k)
            pq.pop();
        answer.push_back(pq.top());
    }
    return answer;
}