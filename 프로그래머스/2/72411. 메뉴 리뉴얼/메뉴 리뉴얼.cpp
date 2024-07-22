#include <bits/stdc++.h>
using namespace std;
/*
코스요리메뉴는 최소 2가지이상의 메뉴, 최소2명이상의 손님으로부터 주문된 단품메뉴의조합
*/
std::unordered_map<std::string, int> combi;
void check(int cur, int length, std::string str, std::string iter)
{
    if(str.size() >= length)
    {
        //std::cout << str <<'\n';
        combi[str]++;
        return;
    }
    for(int i = cur; i < iter.size(); i++)
        check(i+1, length, str+iter[i], iter);
}
vector<string> solution(vector<string> orders, vector<int> course) 
{
    
    for(auto iter : orders)
    {
        std::sort(iter.begin(), iter.end(), std::less<>());
        for(int i = 1; i <= iter.size(); i++)
            check(0, i, "", iter);
    }
    std::unordered_map<int, std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, std::less<std::pair<int, std::string>>>> course_map;
    for(const auto& iter : combi)
        course_map[iter.first.size()].push({iter.second, iter.first});
    vector<string> answer;
    
    for(const auto& num : course)
    {
        if(course_map.find(num) == course_map.end())
            continue;
        int cnt = course_map[num].top().first;
        if(cnt < 2)
            continue;
        while(course_map[num].size() && course_map[num].top().first >= cnt)
        {
            answer.push_back(course_map[num].top().second);
            course_map[num].pop();
        }
    }
    std::sort(answer.begin(), answer.end(), std::less<>());
    return answer;
}