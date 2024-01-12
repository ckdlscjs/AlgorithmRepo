#include <bits/stdc++.h>

using namespace std;
std::vector<int> chks;
void Checks(int idx, std::string str)
{
    if(idx >= 7)
    {
        chks.push_back(std::stoi(str) * 5);
    }
    else
    {
        Checks(idx+1, str + "0");
        Checks(idx+1, str + "1");
    }
}
vector<int> solution(int l, int r) 
{
    std::vector<int> answer;
    Checks(0, "");
    for(const auto& num : chks)
        if(num >= l && num <= r)
            answer.push_back(num);
    
    if(answer.empty())
        answer.push_back(-1);
    return answer;
}