#include <bits/stdc++.h>
using namespace std;
int calctime(const std::string& t)
{
    return std::stoi(t.substr(0, 2)) * 60 + std::stoi(t.substr(3));
}
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) 
{
    int len = calctime(video_len);
    int cur = calctime(pos);
    int st = calctime(op_start);
    int en = calctime(op_end);
    if(st <= cur && cur <= en)
        cur = en;
    for(const auto& iter : commands)
    {
        cur = iter=="prev" ? std::max(cur-10, 0) : std::min(cur+10, len);
        if(st <= cur && cur <= en)
            cur = en;
    }
    std::string minute = std::to_string(cur / 60);
    std::string second = std::to_string(cur % 60);
    if(minute.size() < 2)
        minute = "0" + minute;
    if(second.size() < 2)
        second = "0" + second;
    return minute + ":" +second;
}