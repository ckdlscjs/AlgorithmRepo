//school.programmers.co.kr/learn/courses/30/lessons/17684
#include <bits/stdc++.h>
using namespace std;
std::unordered_map<std::string, int> words;
vector<int> solution(string msg) 
{
    int len = 1;
    for(int i = 0; i < 26; i++)
        words[std::string(1, 'A' + i)] = words.size()+1;
    vector<int> answer;
    while(msg.size())
    {
        std::string w = "";
        for(int i = len; i >= 1; i--)
        {
            if(msg.size() < i)
                continue;
            w = msg.substr(0, i);
            if(words.find(w) != words.end())
            {
                msg = msg.substr(i);
                break;
            }
        }
        answer.push_back(words[w]);
        if(msg.size())
        {
            w += msg[0];
            len = std::max(len, (int)w.size());
            words[w] = words.size()+1;
        }
    }
    return answer;
}