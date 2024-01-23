#include <bits/stdc++.h>

using namespace std;

string solution(string new_id) 
{
    
    for(auto& ch : new_id)
    {
        if('A' <= ch && ch <= 'Z')
        {
            ch += 32;
        }
    }
    for(auto& ch : new_id)
    {
        if(
            !('a' <= ch && ch <= 'z') &&
            !('0' <= ch && ch <= '9') &&
            !(ch == '-') &&
            !(ch == '_') &&
            !(ch == '.')
        )
        {
            ch = ' ';
        }
    }
    
    while(new_id.find(' ') != std::string::npos)
    {
        new_id.erase(new_id.find(' '), 1);
    }
    bool prev_dot = false;
    for(auto& ch : new_id)
    {
        if(ch == '.')
        {
            if(prev_dot)
            {
                ch = ' ';
            }
            else
            {
                prev_dot = true;
            }
        }
        else
        {
           prev_dot = false; 
        }    
    }
    while(new_id.find(' ') != std::string::npos)
    {
        new_id.erase(new_id.find(' '), 1);
    }
    if(new_id[0] == '.')
        new_id[0] = ' ';
    if(new_id[new_id.size()-1] == '.')
        new_id[new_id.size()-1] = ' ';
    while(new_id.find(' ') != std::string::npos)
    {
        new_id.erase(new_id.find(' '), 1);
    }
    if(new_id.empty())
        new_id+='a';
    if(new_id.size() >= 16)
    {
        new_id.erase(15);
        if(new_id[14] == '.')
            new_id.erase(14);
    }
    if(new_id.size() <= 2)
    {
        while(new_id.size() < 3)
        {
            new_id += new_id[new_id.size()-1];
        }
    }
    return new_id;
}