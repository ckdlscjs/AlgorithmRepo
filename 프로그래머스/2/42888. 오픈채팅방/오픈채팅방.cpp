#include <bits/stdc++.h>
using namespace std;
vector<string> solution(vector<string> record) 
{
    std::unordered_map<std::string, std::string> map_id;
    for(auto iter : record)
    {
        std::string order = iter.substr(0, iter.find(' '));
        iter.erase(0, iter.find(' ') + 1);
        std::string id = iter.substr(0, iter.find(' '));
        iter.erase(0, iter.find(' ') + 1);
        std::string nickname = iter;
        if(order == "Enter" || order == "Change")
        {
            map_id[id] = nickname;
        }
    }
    vector<string> answer;
    for(auto iter : record)
    {
        std::string order = iter.substr(0, iter.find(' '));
        iter.erase(0, iter.find(' ') + 1);
        std::string id = iter.substr(0, iter.find(' '));
        iter.erase(0, iter.find(' ') + 1);
        std::string str = "";
        str += map_id[id];
        if(order == "Enter")
            str += "님이 들어왔습니다.";
        else if(order == "Leave")
            str += "님이 나갔습니다.";
        else
            continue;
        answer.push_back(str);
    }
    return answer;
}