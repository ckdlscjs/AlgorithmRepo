#include <bits/stdc++.h>

using namespace std;
std::deque<int> dq;
int solution(vector<int> stones, int k) 
{
    int answer = 200'000'001;
    for(int i = 0; i < stones.size(); i++)
    {
        while(dq.size() && i - dq.front() >= k) 
            dq.pop_front();
        while(dq.size() && stones[dq.back()] <= stones[i]) 
            dq.pop_back();
        dq.push_back(i);
        if(i >= k-1)
            answer = std::min(answer, stones[dq.front()]);
    }
    return answer;
}