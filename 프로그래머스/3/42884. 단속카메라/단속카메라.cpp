#include <bits/stdc++.h>
using namespace std;
int solution(vector<vector<int>> routes) 
{
    std::sort(routes.begin(), routes.end(), [](const std::vector<int>& a, const std::vector<int>& b){
        return a[1] < b[1];
    });
    int right = routes[0][1];
    int answer = 1;
    for(int i = 1; i < routes.size(); i++)
    {
        if(right < routes[i][0])
        {
            answer++;
            right = routes[i][1];
        }
    }
    
    return answer;
}