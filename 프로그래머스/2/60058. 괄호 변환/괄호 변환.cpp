//https://school.programmers.co.kr/learn/courses/30/lessons/60058
#include <bits/stdc++.h>
using namespace std;
string solution(string p) 
{
    if(p.empty())
        return "";
    bool chk = (p[0] == '(' ? true : false);
    int cnt_l = 0, cnt_r = 0;
    std::string u = "", v = "";
    for(const auto& ch : p)
    {
        u += ch;
        if(ch == '(') cnt_l++;
        else cnt_r++;
        if(cnt_l == cnt_r)
            break;
    }
    v = p.substr(cnt_l + cnt_r);
    v = solution(v);
    if(!chk)
    {
        std::string temp = "";
        temp += '(';
        temp += v;
        temp += ')';
        for(int i = 1; i < u.size() - 1; i++)
            u[i] = (u[i] == '(' ? ')' : '(');
        temp += u.substr(1, u.size()-2);
        return temp;
    }
    else
        return u+v;
}