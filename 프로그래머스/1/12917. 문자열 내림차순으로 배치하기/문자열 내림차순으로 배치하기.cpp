//https://school.programmers.co.kr/learn/courses/30/lessons/12917
#include <bits/stdc++.h>
using namespace std;
string solution(string s) 
{
    std::sort(s.begin(), s.end(), std::greater<>());
    return s;
}