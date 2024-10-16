//https://school.programmers.co.kr/learn/courses/30/lessons/72411
#include <bits/stdc++.h>
using namespace std;
std::vector<std::pair<std::string, int>> results[15];
std::map<std::string, int> menus;
void Check(const std::string& order, int length, std::string menu, int idx)
{
    if(menu.size() >= length)
    {
        menus[menu]++;
        return;
    }
    for(int i = idx; i < order.size(); i++)
        Check(order, length, menu + order[i], i+1);
}
vector<string> solution(vector<string> orders, vector<int> course) 
{
    for(auto& iter : orders)
    {
        std::sort(iter.begin(), iter.end(), std::less<>());
        for(const auto& cnt : course)
            Check(iter, cnt, {}, 0);
    }
        
    for(const auto& iter : menus)
    {
        if(iter.second <= 1)
            continue;
        results[iter.first.size()].push_back(iter);
    }
    vector<string> answer;
    for(const auto& iter : course)
    {
        std::sort(results[iter].begin(), results[iter].end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
                  {
                      return a.second == b.second ? a.first < b.first : a.second > b.second;
                  });
        for(int i = 0; i < results[iter].size() && results[iter][i].second == results[iter][0].second; i++)
            answer.push_back(results[iter][i].first);
    }
    std::sort(answer.begin(), answer.end(), std::less<>());
    return answer;
}