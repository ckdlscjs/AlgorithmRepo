//https://school.programmers.co.kr/learn/courses/30/lessons/12979
#include <bits/stdc++.h>
using namespace std;
std::queue<std::pair<int, int>> q;
int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    std::sort(stations.begin(), stations.end(), std::less<>());
    for(const auto& iter : stations)
        q.push({iter-w, std::min(iter+w, n)});
    q.push({n+1, n+1});
    int l = 0, r = 0;
    if(q.front().first > 1)
    {
        int cnt = (q.front().first - r - 1) / (w*2+1) + ((q.front().first - r - 1) % (w*2+1) ? 1 : 0);
        answer += cnt;
        l = 1;
        r = (w*2 + 1) * cnt;
    }
    
    while(q.size())
    {
        std::pair<int, int> cur = q.front();
        q.pop();
        if(cur.first > r)
        {
            answer += (cur.first - r - 1) / (w*2+1) + ((cur.first-r-1) % (w*2+1) ? 1 :0);
            l = cur.first;
            r = cur.second;
        }
        else
            r = cur.second;
    }
    return answer;
}