//school.programmers.co.kr/learn/courses/30/lessons/17684
#include <bits/stdc++.h>
using namespace std;
std::unordered_map<std::string, int> words;
vector<int> solution(string msg) 
{
    int idx = 1;
    for(; idx <= 26; idx++)
    {
        std::string str = "A";
        str[0] += idx-1;
        words[str] = idx;
    }
    vector<int> answer;
    int len = 1;
    while(msg.size())
    {
        std::string word = "";
        for(int i = len; i >= 1; i--)
        {
            if(msg.size() < i)
                continue;
            word = msg.substr(0, i);
            if(words.find(word) != words.end())
            {
                msg = msg.substr(i);
                break;
            }
        }
        answer.push_back(words[word]);
        if(msg.size())
        {
            word += msg[0];
            len = std::max(len, (int)word.size());
            words[word] = idx++;
        }
    }
    
    return answer;
}