//https://school.programmers.co.kr/learn/courses/30/lessons/42888
#include <bits/stdc++.h>
using namespace std;
std::vector<std::pair<std::string, std::string>> results;
std::unordered_map<std::string, std::string> db;
vector<string> solution(vector<string> record) 
{
    for(auto iter : record)
    {
        int it = iter.find(' ');
        std::string order = iter.substr(0, it); 
        iter = iter.substr(it+1);
        
        it = iter.find(' ');
        std::string uid = iter.substr(0, it); 
        iter = iter.substr(it+1);
        if(order == "Enter" || order == "Change")
            db[uid] = iter;
        if(order == "Change")
            continue;
        results.push_back({uid, order});
    }
    vector<string> answer;
    std::string str;
    for(const auto& iter : results)
    {
        str += db[iter.first];
        str += "님이 ";
        str += iter.second == "Enter" ? "들어왔습니다." : "나갔습니다.";
        answer.push_back(str);
        str.clear();
    }
    return answer;
}