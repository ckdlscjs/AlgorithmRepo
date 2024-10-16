//https://school.programmers.co.kr/learn/courses/30/lessons/42576
#include <bits/stdc++.h>
using namespace std;
std::unordered_map<std::string, int> chks;
string solution(vector<string> participant, vector<string> completion) 
{
    for(const auto& iter : completion)
        chks[iter]--;
    for(const auto& iter : participant)
    {
        chks[iter]++;
        if(chks[iter] > 0)
            return iter;
    }
}