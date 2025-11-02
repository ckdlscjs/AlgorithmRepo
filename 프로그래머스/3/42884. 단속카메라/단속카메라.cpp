#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> routes) 
{
    std::sort(routes.begin(), routes.end(), [](const std::vector<int>& a, const std::vector<int>& b)->bool{
        return a[1] < b[1];
    });
    int answer = 0;
    int cur = -30'005;
    for(const auto& iter : routes)
    {
        if(iter[0] > cur)
        {
            answer++;
            cur = iter[1];
        }
    }
    return answer;
}