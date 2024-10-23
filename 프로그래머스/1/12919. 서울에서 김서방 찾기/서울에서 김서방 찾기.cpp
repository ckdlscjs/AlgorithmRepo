//https://school.programmers.co.kr/learn/courses/30/lessons/12919
#include <bits/stdc++.h>
using namespace std;
string solution(vector<string> seoul) 
{
    for(int i = 0; i < seoul.size(); i++)
    {
        if(seoul[i] == "Kim")
            return "김서방은 " + std::to_string(i) + "에 있다";
    }
}