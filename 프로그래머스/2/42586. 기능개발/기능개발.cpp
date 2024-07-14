#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    std::queue<int> q;
    for(int i = 0; i < progresses.size(); i++)
    {
        int day = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i])
            day++;
        q.push(day);
    }
    vector<int> answer;
    while(q.size())
    {
        int cnt = 1;
        int day = q.front();
        q.pop();
        while(q.size() && q.front() <= day)
        {
            cnt++;
            q.pop();
        }
        answer.push_back(cnt);
    }
    
    return answer;
}