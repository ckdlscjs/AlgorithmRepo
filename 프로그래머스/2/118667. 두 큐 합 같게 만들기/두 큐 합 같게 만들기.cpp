#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) 
{
    int answer = 0;
    int sum1 = 0, sum2 = 0;
    std::queue<int> q1, q2;
    for(const auto& iter : queue1)
    {
        sum1 += iter;
        q1.push(iter);
    }
        
    for(const auto& iter : queue2)
    {
        sum2 += iter;
        q2.push(iter);
    }
        
    while(sum1 != sum2 && answer <= q1.size() + q2.size())
    {
        if(sum1 < sum2)
        {
            q1.push(q2.front());
            sum1 += q2.front();
            sum2 -= q2.front();
            q2.pop();
        }
        else if(sum1 > sum2)
        {
            q2.push(q1.front());
            sum2 += q1.front();
            sum1 -= q1.front();
            q1.pop();
        }
        answer++;
    }
    return answer > q1.size() + q2.size() ? -1 : answer;
}