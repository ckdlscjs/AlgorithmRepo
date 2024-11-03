//https://school.programmers.co.kr/learn/courses/30/lessons/92341
#include <bits/stdc++.h>
using namespace std;
std::unordered_map<std::string, int> timerecord;
std::map<std::string, int> sums;
vector<int> solution(vector<int> fees, vector<string> records) 
{
    for(auto& iter : records)
    {
        std::string t = iter.substr(0, iter.find(' '));
        int time = std::stoi(t.substr(0, 2))*60 + std::stoi(t.substr(3, 2));
        iter = iter.substr(iter.find(' ') + 1);
        std::string num = iter.substr(0, iter.find(' '));
        iter = iter.substr(iter.find(' ') + 1);
        if(iter == "IN")
        {
            timerecord[num] = time;
        }
        else
        {
            sums[num] += time - timerecord[num];
            timerecord[num] = 0;
        }
    }
    for(const auto& iter : timerecord)
    {
        if(iter.second == 0 && sums.find(iter.first) != sums.end()) continue;
        sums[iter.first] += 23*60+59 - iter.second;
    }
    vector<int> answer;
    for(const auto& iter : sums)
        answer.push_back(fees[1] + std::max(0, (int)std::ceil((iter.second - fees[0]) / (double)fees[2]) * fees[3]));
    
    return answer;
}