#include <bits/stdc++.h>
using namespace std;
std::map<char, int> alp;
vector<int> solution(vector<string> keymap, vector<string> targets) 
{
    for(const std::string& str : keymap)
    {
        for(int i = 0; i < str.size(); i++)
        {
            if(!alp[str[i]])
                alp[str[i]] = i + 1;
            else
                alp[str[i]] = std::min(i+1, alp[str[i]]);
            std::cout << str[i] << " : " << alp[str[i]] << '\n';
        }
    }
    vector<int> answer;
    for(const std::string& str : targets)
    {
        int sum = 0;
        for(const char& ch : str)
        {
            if(!alp[ch])
            {
                sum = 0;
                break;
            }
            sum += alp[ch];
        }
            
        answer.push_back(sum ? sum : -1);
    }
    return answer;
}