#include <bits/stdc++.h>
using namespace std;
int GetTime(const std::string& str)
{
    return std::stoi(str.substr(0, 2)) * 60 + std::stoi(str.substr(3));
}
int times[24*60 + 65];
int solution(vector<vector<string>> book_time) 
{
    int answer = 0;
    for(const auto& iter : book_time)
    {
        int st = GetTime(iter[0]);
        int en = GetTime(iter[1]) + 9;
        for(int i = st; i <= en; i++)
        {
            times[i]++;
            answer = std::max(answer, times[i]);
        } 
    }
    return answer;
}