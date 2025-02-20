#include <bits/stdc++.h>
using namespace std;
int calc_time(const std::string& str)
{
    return std::stoi(str.substr(0, 2)) * 60 + std::stoi(str.substr(3));
}
vector<string> solution(vector<vector<string>> plans) 
{
    std::sort(plans.begin(), plans.end(), [](std::vector<std::string>& atom1, std::vector<std::string>& atom2) -> bool
              {
                  return atom1[1] < atom2[1];
              });
    vector<string> answer;
    int cur_time = 0;
    std::deque<std::tuple<std::string, int>> remains;
    for(const auto& iter : plans)
    {
        int iter_time = calc_time(iter[1]);
        int iter_remain = std::stoi(iter[2]);
        while(remains.size() && cur_time + std::get<1>(remains.front()) <= iter_time)
        {
            answer.push_back(std::get<0>(remains.front()));
            cur_time += std::get<1>(remains.front());
            remains.pop_front();
        }
        if(remains.size())
        {
            auto front = remains.front();
            remains.pop_front();
            std::get<1>(front) = cur_time + std::get<1>(front) - iter_time;
            remains.push_front(front);
        }
        remains.push_front({iter[0], iter_remain});
        cur_time = iter_time;
    }
    while(remains.size())
    {
        answer.push_back(std::get<0>(remains.front()));
        remains.pop_front();
    }
        
    return answer;
}