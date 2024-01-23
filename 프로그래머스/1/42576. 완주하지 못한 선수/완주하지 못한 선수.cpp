#include <bits/stdc++.h>
using namespace std;
std::unordered_map<std::string, int> check;
string solution(vector<string> participant, vector<string> completion) 
{
    std::string answer;
    for(const std::string& str : completion)
    {
        check[str]++;
    }
    for(const std::string& str : participant)
    {
        check[str]--;
        if(check[str] < 0)
            answer = str;
    }
    
    return answer;
}