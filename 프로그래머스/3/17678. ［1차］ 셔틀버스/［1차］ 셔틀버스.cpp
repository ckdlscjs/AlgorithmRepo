#include <bits/stdc++.h>
using namespace std;
int ConvInt(const std::string& time)
{
    return std::stoi(time.substr(0, 2)) * 60 + std::stoi(time.substr(3));
}
std::string ConvStr(int time)
{
    std::string h, m;
    if(time / 60 < 10)
        h += "0";
    h += std::to_string(time/60);
    if(time % 60 < 10)
        m += "0";
    m += std::to_string(time%60);
    return h + ":" + m;
}
string solution(int n, int t, int m, vector<string> timetable) 
{
    std::sort(timetable.begin(), timetable.end());
    int cur = ConvInt("09:00");
    int answer = 0;
    int idx = 0;
    for(int i = 0; i < n; i++)
    {
        int cnt = 0;
        for(idx; idx < timetable.size() && cnt < m && ConvInt(timetable[idx]) <= cur; idx++)
        {
            answer = std::max(answer, ConvInt(timetable[idx]) - 1);
            cnt++;
        }
        if(cnt < m)
            answer = cur;
        cur += t;
    }
    return ConvStr(answer);
}