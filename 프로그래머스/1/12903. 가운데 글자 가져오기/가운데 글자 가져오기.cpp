//https://school.programmers.co.kr/learn/courses/30/lessons/12903
#include <bits/stdc++.h>
using namespace std;

string solution(string s) 
{
    return s.size() % 2 ? std::string(1, s[s.size() / 2]) : std::string(1, s[s.size() / 2 - 1]) + s[s.size()/2];
}