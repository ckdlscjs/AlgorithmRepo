#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    std::queue<int> q;
    vector<int> answer;
    for(int i = 0; i < progresses.size(); i++)
    {
        int open = ((100-progresses[i]) / speeds[i]) + ((100-progresses[i]) % speeds[i] ? 1 : 0);
        //std::cout << open <<'\n';
        if(q.empty() || q.front() > open)
        {
            q.push(open);
            continue;
        }
        int cnt = 0;
        while(q.size() && q.front() < open)
        {
            q.pop();
            cnt++;
        }
        if(cnt)
            answer.push_back(cnt);
        q.push(open);
    }
    if(q.size())
        answer.push_back(q.size());
    return answer;
}