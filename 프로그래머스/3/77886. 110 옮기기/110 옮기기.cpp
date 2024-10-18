//https://school.programmers.co.kr/learn/courses/30/lessons/77886
#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> s) 
{
    vector<string> answer;
    for(const auto& iter : s)
    {
        std::string temp = "";
        int cnt = 0;
        for(int i = 0; i < iter.size(); i++)
        {
            temp += iter[i];
            if(temp.size() >= 3 && temp.substr(temp.size() - 3) == "110")
            {
                cnt++;
                temp = temp.substr(0, temp.size()-3);
            }
        }
        int idx = temp.size()-1;
        while(idx >= 0)
        {
            if(temp[idx] == '0')
            {
                std::string temp110 = "";
                for(int i = 0; i < cnt; i++)
                    temp110 += "110";
                temp = temp.substr(0, idx+1) + temp110 + temp.substr(idx+1);
                break;
            }
            idx--;
        }
        if(temp.size() < iter.size())
        {
            std::string temp110 = "";
            for(int i = 0; i < cnt; i++)
                temp110 += "110";
            temp = temp110 + temp;
        }
        answer.push_back(temp);
    }
    
    return answer;
}