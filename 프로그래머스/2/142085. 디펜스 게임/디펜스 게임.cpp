//https://school.programmers.co.kr/learn/courses/30/lessons/142085
#include <bits/stdc++.h>
using namespace std;
int solution(int n, int k, vector<int> enemy) 
{
    std::priority_queue<int, std::vector<int>, std::less<int>> pq;
    int sum = 0;
    int answer = 0;
    for(const auto& iter : enemy)
    {
        sum += iter;
        pq.push(iter);
        if(sum > n)
        {
            while(k && pq.size() && sum > n)
            {
                k--;
                sum -= pq.top();
                pq.pop();
            }
            if(sum > n)
                break;
        }
        answer++;
    }
    return answer;
}