//https://school.programmers.co.kr/learn/courses/30/lessons/134240
#include <bits/stdc++.h>
using namespace std;
std::string Check(const std::vector<int>& food, int idx)
{
    std::string res = "";
    if(idx >= food.size())
        return "0";
    for(int i = 0; i < food[idx] / 2; i++)
        res += std::to_string(idx);
    res += Check(food, idx+1);
    for(int i = 0; i < food[idx] / 2; i++)
        res += std::to_string(idx);
    return res;
}
string solution(vector<int> food) 
{
    return Check(food, 1);
}