//https://school.programmers.co.kr/learn/courses/30/lessons/12925
#include <bits/stdc++.h>
using namespace std;
std::string solution(int n) 
{
    std::string answer = "";
    for(int i = 0; i < n; i++)
        answer += i % 2 ? "박" : "수";
    return answer;
}