#include <bits/stdc++.h>

using namespace std;

string solution(string w) 
{
    if(w.empty()) return w;
    int cl = 0, cr = 0;
    bool chk = w[0] == '(';
    std::string u, v;
    for(const auto& ch : w)
    {
        u += ch;
        cl += ch == '(';
        cr += ch == ')';
        if(cl == cr) break;
    }
    v = w.substr(u.size());
    std::string recursive = solution(v);
    if(chk)
    {
        return u + recursive;
    }
    else
    {
        u = std::string(u.begin()+1, u.end()-1);
        for(auto& ch : u)
            ch = ch == '(' ? ')' : '(';
        return "(" + recursive + ")" + u;
    }
}