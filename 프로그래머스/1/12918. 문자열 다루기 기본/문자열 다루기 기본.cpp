//https://school.programmers.co.kr/learn/courses/30/lessons/12918
#include <bits/stdc++.h>
using namespace std;
bool solution(string s) 
{
    if(s.size() != 4 && s.size() != 6)
        return false;
    for(const auto& iter : s)
        if(!('0' <= iter && iter <= '9'))
            return false;
    return true;
}