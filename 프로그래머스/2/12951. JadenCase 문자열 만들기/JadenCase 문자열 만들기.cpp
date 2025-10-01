#include <bits/stdc++.h>

using namespace std;

string solution(string s) 
{
    bool first = true;
    for(auto& ch : s)
    {
        if(ch == ' ')
        {
            first = true;
            continue;
        }
        
        if(first)
        {   
            first = false;
            if(isdigit(ch)) continue;
            if('a' <= ch && ch <= 'z') ch -= 32;
        }
        else
        {
            if('A' <= ch && ch <= 'Z') ch += 32;
        }
    }
    return s;
}