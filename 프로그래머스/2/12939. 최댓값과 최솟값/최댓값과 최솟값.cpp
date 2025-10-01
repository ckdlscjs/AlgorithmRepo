#include <bits/stdc++.h>

using namespace std;

string solution(string s) 
{
    std::vector<int> strs;
    std::string str;
    for(const auto& ch : s)
    {
        if(ch == ' ')
        {
            strs.push_back(std::stoi(str));
            //std::cout << str << '\n';
            str.clear();
        }
        else
        {
            str += ch;
        }
    }
    strs.push_back(std::stoi(str));
    std::sort(strs.begin(), strs.end());
    return (std::to_string(*strs.begin()) + ' ' + std::to_string(*--strs.end()));
}