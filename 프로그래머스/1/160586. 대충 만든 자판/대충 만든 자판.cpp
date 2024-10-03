//https://school.programmers.co.kr/learn/courses/30/lessons/160586
#include <bits/stdc++.h>
using namespace std;
std::unordered_map<char, int> keys;
vector<int> solution(vector<string> keymap, vector<string> targets) 
{
    for(const auto& iter : keymap)
    {
        for(int i = 0; i < iter.size(); i++)
        {
            if(keys[iter[i]] == 0)
                keys[iter[i]] = i+1;
            else
                keys[iter[i]] = std::min(keys[iter[i]], i+1);
        }
    }
    vector<int> answer;
    for(const auto& iter : targets)
    {
        int sum = -1;
        for(const auto& it : iter)
        {
            if(keys[it] != 0)
                sum += keys[it];
            else
            {
                sum = -1;
                break;
            }
        }
        answer.push_back(sum > -1 ? sum+1: -1);
    }
    return answer;
}