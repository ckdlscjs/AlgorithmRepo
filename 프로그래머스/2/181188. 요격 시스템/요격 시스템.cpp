#include <bits/stdc++.h>
using namespace std;
int solution(vector<vector<int>> targets) 
{
    std::sort(targets.begin(), targets.end(), [](const std::vector<int>& a, const std::vector<int>& b)
              {
                 return a[1] < b[1]; 
              });
    int right = targets[0][1] - 1;
    int answer = 1;
    for(const auto& iter : targets)
    {
        if(iter[0] > right)
        {
            right = iter[1] - 1;
            answer++;
        }
    }
    
    return answer;
}