//https://school.programmers.co.kr/learn/courses/30/lessons/12925
#include <bits/stdc++.h>
using namespace std;

int solution(string s) 
{
    int ret = 0;
    int idx = (s[0] == '+' || s[0] == '-') ? 1 : 0;
    for(idx; idx < s.size(); idx++)
        ret = ret * 10 + s[idx] -'0';
    if(s[0] == '-')
        ret *= -1;
    return ret;
}