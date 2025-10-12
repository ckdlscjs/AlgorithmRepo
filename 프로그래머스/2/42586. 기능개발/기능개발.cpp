#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    std::queue<int> q;
    int cnt = 0;
    for(int i = 0; i < progresses.size(); i++)
    {
        int need = (100 - progresses[i]) / speeds[i] + ((100 - progresses[i]) % speeds[i] ? 1 : 0);
        if(q.empty())
        {
            q.push(need);
        }
        else
        {
            if(need > q.front())
            {
                q.pop();
                answer.push_back(cnt);
                cnt = 0;
                q.push(need);
            }
        }
        cnt++;
    }
    if(q.size())
        answer.push_back(cnt);
    return answer;
}