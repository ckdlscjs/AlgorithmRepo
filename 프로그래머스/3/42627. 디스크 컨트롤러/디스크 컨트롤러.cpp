#include <bits/stdc++.h>

using namespace std;
//소요시간, 요청시각, 작업번호
#define tiii std::tuple<int, int, int> 
struct comp
{
    bool operator()(const tiii& a, const tiii& b)
    {
        if(std::get<0>(a) == std::get<0>(b))
        {
            if(std::get<1>(a) == std::get<1>(b))
            {
                return std::get<2>(a) > std::get<2>(b);
            }
            return std::get<1>(a) > std::get<1>(b);
        }
        return std::get<0>(a) > std::get<0>(b);
    }
};
std::priority_queue<tiii, std::vector<tiii>, comp> pq;
int solution(vector<vector<int>> inputs) 
{
    std::vector<tiii> jobs;
    for(int i = 0; i < inputs.size(); i++)
        jobs.push_back({inputs[i][0], inputs[i][1], i});
    std::sort(jobs.begin(), jobs.end(), std::less<>());
    int idx = 0, cur = 0, answer = 0;
    while(idx < jobs.size() || pq.size())
    {
        if(idx < jobs.size() && std::get<0>(jobs[idx]) <= cur)
        {
            pq.push({std::get<1>(jobs[idx]), std::get<0>(jobs[idx]), std::get<2>(jobs[idx])});
            idx++;
            continue;
        }
        if(pq.size())
        {
            cur += std::get<0>(pq.top());
            answer += cur - std::get<1>(pq.top());
            pq.pop();
        }
        else
            cur = std::get<0>(jobs[idx]);
    }
    
    return answer / jobs.size();
}