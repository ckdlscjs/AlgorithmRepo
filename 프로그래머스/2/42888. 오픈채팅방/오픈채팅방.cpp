#include <bits/stdc++.h>
using namespace std;

std::unordered_map<std::string, std::string> uid_name;
vector<string> solution(vector<string> record) 
{
    vector<std::string> uids;
    vector<std::string> answer;
    for(const auto& iter : record)
    {
        std::string uid, name;
        std::string str = iter.substr(iter.find(' ') + 1);
        size_t pos = str.find(' ');
        uid = str.substr(0, pos);
        name = str.substr(pos + 1);
        //std::cout << uid << ' ' << name << '\n';
        if(iter[0] == 'E' || iter[0] == 'C') uid_name[uid] = name;
        if(iter[0] == 'C') 
            continue;
        //std::cout << uid << '\n';        
        uids.push_back(uid);
        if(iter[0] == 'E') answer.push_back("님이 들어왔습니다.");
        else if(iter[0] == 'L') answer.push_back("님이 나갔습니다.");
    }
    for(int i = 0; i < uids.size(); i++)
    {
        answer[i] = uid_name[uids[i]] + answer[i];
    }
    return answer;
}