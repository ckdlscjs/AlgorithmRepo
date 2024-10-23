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
    w = w*2+1;
    int r = 0;
    if(q.front().first > 1)
    {
        int cnt = std::ceil((q.front().first - r - 1) / (double)w);
        answer += cnt;
        r = w * cnt;
    }
    
    while(q.size())
    {
        std::pair<int, int> cur = q.front();
        q.pop();
        if(cur.first > r)
            answer += std::ceil((cur.first - r - 1) / (double)w);
        r = cur.second;
    }
    return answer;
}