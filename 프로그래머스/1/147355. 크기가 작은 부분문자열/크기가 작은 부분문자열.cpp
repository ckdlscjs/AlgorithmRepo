//https://school.programmers.co.kr/learn/courses/30/lessons/147355
#include <bits/stdc++.h>
using namespace std;

int solution(string t, string p) 
{
    int answer = 0;
    for(int i = 0; i <= t.size() - p.size(); i++)
    {
        std::string st = t.substr(i, p.size());
        answer += st <= p ? 1 : 0;
            
    }
    return answer;
}