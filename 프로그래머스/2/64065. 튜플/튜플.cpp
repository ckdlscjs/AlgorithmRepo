#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) 
{
    std::unordered_map<int, int> cnts;
    std::string num;
    for(int i = 1; i < s.size()-1; i++)
    {
        if(s[i] == '{') continue;
        else if(s[i] == ',' || s[i] == '}')
        {
            if(num.empty()) continue;
            cnts[std::stoi(num)]++;
            num.clear();
        }
        else
            num += s[i];
    }
    vector<int> answer;
    for(const auto& iter : cnts)
        answer.push_back(iter.first);
    std::sort(answer.begin(), answer.end(), [&](const int& a, const int& b)->bool{
       return cnts[a] > cnts[b];
    });
    return answer;
}