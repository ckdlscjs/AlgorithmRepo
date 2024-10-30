//https://school.programmers.co.kr/learn/courses/30/lessons/17677
#include <bits/stdc++.h>
using namespace std;
int solution(string str1, string str2) 
{
    for(auto& ch : str1)
        if('a' <= ch && ch <= 'z')
            ch-=32;
    for(auto& ch : str2)
        if('a' <= ch && ch <= 'z')
            ch-=32;
    std::unordered_map<std::string, int> var_str1;
    std::unordered_map<std::string, int> var_str2;
    for(int i = 0; i < str1.size()-1; i++)
    {
        std::string temp = str1.substr(i, 2);
        if(!('A' <= temp[0] && temp[0] <= 'Z') || !('A' <= temp[1] && temp[1] <= 'Z'))
            continue;
        var_str1[temp]++;
    }
    for(int i = 0; i < str2.size()-1; i++)
    {
        std::string temp = str2.substr(i, 2);
        if(!('A' <= temp[0] && temp[0] <= 'Z') || !('A' <= temp[1] && temp[1] <= 'Z'))
            continue;
        var_str2[temp]++;
    }
    int val_intersection = 0, val_union = 0;
    for(const auto& iter : var_str1)
    {
        if(var_str2.find(iter.first) == var_str2.end())
            val_union += iter.second;
        else
        {
            val_intersection += std::min(iter.second, var_str2[iter.first]);
            val_union += std::max(iter.second, var_str2[iter.first]);
        }
    }
    for(const auto& iter : var_str2)
    {
        if(var_str1.find(iter.first) == var_str1.end())
            val_union += iter.second;
    }
    if(val_intersection == val_union)
        return 65536;
    return (int)((double)val_intersection / (double)val_union * 65'536);
}