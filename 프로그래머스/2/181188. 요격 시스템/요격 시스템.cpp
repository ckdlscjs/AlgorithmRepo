#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> targets) 
{
    std::sort(targets.begin(), targets.end(), [](const std::vector<int>& a, const std::vector<int>& b)
              {
                  return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
              });
    int answer = 0, cr = 0;
    for(const auto& iter : targets)
    {
        //std::cout << iter[0] << ' ' << iter[1] << '\n';
        if(iter[0] >= cr)
        {
            cr = iter[1];
            answer++;
        }
    }
    
    return answer;
}