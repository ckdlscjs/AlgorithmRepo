//https://school.programmers.co.kr/learn/courses/30/lessons/64065
#include <bits/stdc++.h>
using namespace std;
std::unordered_map<int, int> cnts;
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>> pq;
vector<int> solution(string s) 
{
    std::string num;
    for(const auto& iter : s)
    {
        if(num.size() && !std::isdigit(iter))
        {
            cnts[std::stoi(num)]++;
            num.clear();
        }
        else if(std::isdigit(iter))
        {
            num += iter;
        }
    }
    
    for(const auto& iter : cnts)
        pq.push({iter.second, iter.first});
    vector<int> answer;
    while(pq.size())
        answer.push_back(pq.top().second), pq.pop();
    return answer;
}