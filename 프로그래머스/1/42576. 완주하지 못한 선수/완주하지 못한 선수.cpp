#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    string answer = "";
    std::unordered_map<std::string, int> complet;
    for(const auto& iter : completion)
        complet[iter]++;
    for(const auto& iter : participant)
    {
        complet[iter]--;
        if(complet[iter] < 0)
            answer = iter;
    }
    return answer;
}