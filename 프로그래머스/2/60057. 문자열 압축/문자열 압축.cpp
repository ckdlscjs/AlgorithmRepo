//https://school.programmers.co.kr/learn/courses/30/lessons/60057
#include <bits/stdc++.h>
using namespace std;

int solution(string s) 
{
    int answer = s.size();
    for(int len = 1; len <= s.size(); len++)
    {   
        std::string str = s;
        std::string temp = "";
        int cnt = 0;
        std::string result = "";
        while(str.size() >= len)
        {
            if(temp.empty())
            {
                temp = str.substr(0, len);
                str = str.substr(len);
                cnt++;
            }
            else
            {
                if(str.substr(0, len) == temp)
                {
                    str = str.substr(len);
                    cnt++;
                }
                else
                {
                    if(cnt >= 2)
                        temp = std::to_string(cnt) + temp;
                    result += temp;
                    temp.clear();
                    cnt = 0;
                }
            }
        }
        if(temp.size())
        {
            if(cnt >= 2)
                temp = std::to_string(cnt) + temp;
            result += temp;
        }
        if(str.size())
        {
            result += str;
        }
        answer = std::min(answer, (int)result.size());
    }
    return answer;
}