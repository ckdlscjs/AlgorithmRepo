//https://school.programmers.co.kr/learn/courses/30/lessons/133499
#include <bits/stdc++.h>
using namespace std;
int solution(vector<string> babbling) 
{
    int answer = 0;
    for(std::string str : babbling)
    {
        auto iter = str.find("aya");
        while(str.find("ayaaya") == std::string::npos && iter != std::string::npos)
        {
            str.replace(iter, 3, "...");
            iter = str.find("aya");
        }
        iter = str.find("ye");
        while(str.find("yeye") == std::string::npos && iter != std::string::npos)
        {
            str.replace(iter, 2, "..");
            iter = str.find("ye");
        }
        iter = str.find("woo");
        while(str.find("woowoo") == std::string::npos && iter != std::string::npos)
        {
            str.replace(iter, 3, "...");
            iter = str.find("woo");
        }
        iter = str.find("ma");
        while(str.find("mama") == std::string::npos && iter != std::string::npos)
        {
            str.replace(iter, 3, "..");
            iter = str.find("ma");
        }
        bool chk = true;
        for(const auto& ch : str)
        {
            if(ch != '.')
                chk = false;
        }
        //std::cout << str << '\n';
        answer += chk ? 1 : 0;
    }
    return answer;
}