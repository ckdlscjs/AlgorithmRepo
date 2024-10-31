//https://school.programmers.co.kr/learn/courses/30/lessons/49993
#include <bits/stdc++.h>
using namespace std;
int solution(string skill, vector<string> skill_trees) 
{
    int alps = 0;
    std::unordered_set<std::string> chks;
    std::string skills = "";
    for(const auto& ch : skill)
    {
        alps |= 1 << (ch-'A');
        skills += ch;
        chks.insert(skills);
    }
    int answer = 0;
    for(const auto& iter : skill_trees)
    {
        std::string temp = "";
        for(const auto& ch : iter)
        {
            if(alps & 1 << (ch - 'A'))
                temp += ch;
        }
        answer += (chks.find(temp) != chks.end() ? 1 : 0);
        answer += temp.empty() ? 1 : 0;
    }
    return answer;
}