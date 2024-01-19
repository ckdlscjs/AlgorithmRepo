#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string my_string) 
{
    vector<int> answer;
    for(const auto& ch : my_string)
    {
        if('0' <= ch && ch <= '9')
            answer.push_back(ch-'0');
    }
    std::sort(answer.begin(), answer.end());
    return answer;
}