#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;
    for(const auto& iter : commands)
    {
        std::vector<int> temps(array.begin()+iter[0]-1, array.begin()+iter[1]);
        std::sort(temps.begin(), temps.end(), std::less<>());
        answer.push_back(temps[iter[2]-1]);
    }
    return answer;
}