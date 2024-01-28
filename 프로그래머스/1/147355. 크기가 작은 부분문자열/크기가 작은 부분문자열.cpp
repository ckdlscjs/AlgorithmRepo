#include <bits/stdc++.h>
using namespace std;

int solution(string t, string p) 
{
    int answer = 0;
    for(int i = 0; i <= t.size() - p.size(); i++)
    {
        std::string st = t.substr(i, p.size());
        if(std::stoll(p) >= std::stoll(st))
        {
            answer++;
        }
            
    }
    return answer;
}