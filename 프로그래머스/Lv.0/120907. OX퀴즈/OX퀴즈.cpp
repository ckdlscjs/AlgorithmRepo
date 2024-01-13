#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> quiz) 
{
    vector<string> answer;
    for(const std::string& str : quiz)
    {
        std::string st[5];
        int st_idx = 0;
        for(int idx = 0; idx < str.size(); idx++)
        {
            if(str[idx] == ' ')
                st_idx++;
            else
                st[st_idx] += str[idx];
        }
        if(st[1] == "+")
            answer.push_back(std::stoi(st[4]) == std::stoi(st[0]) + std::stoi(st[2]) ? "O" : "X");
        else
            answer.push_back(std::stoi(st[4]) == std::stoi(st[0]) - std::stoi(st[2]) ? "O" : "X");
    }
    return answer;
}