//https://school.programmers.co.kr/learn/courses/30/lessons/72410
#include <bits/stdc++.h>
using namespace std;
string solution(string new_id) 
{
    char chk3;
    for(auto iter = new_id.begin(); iter != new_id.end();)
    {
        if('A' <= *iter && *iter <= 'Z')
        {
            *iter += 32;
        }
        else if(!('a' <= *iter && *iter <= 'z') && !('0' <= *iter && *iter <= '9') && *iter != '-' && *iter != '_' && *iter != '.')
        {
            iter = new_id.erase(iter);
            continue;
        }
        else if(chk3 == '.' && *iter == '.')
        {
            iter = new_id.erase(iter);
            continue;
        }
        chk3 = *iter;
        iter++;
    }
    if(*new_id.begin() == '.')
        new_id.erase(0, 1);
    if(*new_id.rbegin() == '.')
        new_id.erase(new_id.size()-1, 1);
    if(new_id.empty())
        new_id += "a";
    if(new_id.size() >= 16)
    {
        new_id = new_id.substr(0,15);
        if(*new_id.rbegin() == '.')
            new_id.erase(new_id.size()-1, 1);
    }
    while(new_id.size() < 3)
    {
        new_id += *new_id.rbegin();
    }
    return new_id;
}