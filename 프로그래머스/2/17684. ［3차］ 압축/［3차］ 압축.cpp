#include <bits/stdc++.h>
using namespace std;
std::unordered_map<std::string, int> dic;
vector<int> solution(string msg) 
{
    int idx = 1;
    for(idx = 1; idx <= 26; idx++)
        dic[std::string(1, 'A' + idx - 1)] = idx;
    std::string str;
    vector<int> answer;
    for(const auto& iter : msg)
    {
        std::string temp = str;
        str += iter;
        if(dic.find(str) != dic.end()) continue;
        answer.push_back(dic[temp]);
        dic[str] = idx++;
        str = iter;
    }
    answer.push_back(dic[str]);
    return answer;
}