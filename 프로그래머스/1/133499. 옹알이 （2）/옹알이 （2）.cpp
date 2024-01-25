#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> babbling) 
{
    int answer = 0;
    for(auto& str : babbling)
    {
        std::string word = "aya";
        while(str.find(word) != std::string::npos)
        {
            if(str[str.find(word)-1] == '1')
                break;
            str.replace(str.find(word), word.size(), "111");
        }
        word = "ye";
        while(str.find(word) != std::string::npos)
        {
            if(str[str.find(word)-1] == '2')
                break;
            str.replace(str.find(word), word.size(), "22");
        }
        word = "woo";
        while(str.find(word) != std::string::npos)
        {
            if(str[str.find(word)-1] == '3')
                break;
            str.replace(str.find(word), word.size(), "333");
        }
        word = "ma";
        while(str.find(word) != std::string::npos)
        {
            if(str[str.find(word)-1] == '4')
                break;
            str.replace(str.find(word), word.size(), "44");
        }
        while(str.find('1') != std::string::npos)
        {
            str.erase(str.find('1'), 1);
        }
        while(str.find('2') != std::string::npos)
        {
            str.erase(str.find('2'), 1);
        }
        while(str.find('3') != std::string::npos)
        {
            str.erase(str.find('3'), 1);
        }
        while(str.find('4') != std::string::npos)
        {
            str.erase(str.find('4'), 1);
        }
        std::cout << str << '\n';
        if(str.empty())
            answer++;
    }
    return answer;
}