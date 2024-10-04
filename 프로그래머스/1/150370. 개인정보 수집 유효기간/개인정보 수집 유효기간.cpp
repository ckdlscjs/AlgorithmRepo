#include <bits/stdc++.h>
using namespace std;
std::unordered_map<char, int> t;
vector<int> solution(string today, vector<string> terms, vector<string> privacies) 
{
    for(const auto& iter : terms)
        t[iter[0]] = std::stoi(iter.substr(2));
    vector<int> answer;
    for(int i = 0; i < privacies.size(); i++)
    {
        int t_year = std::stoi(today.substr(0,4));
        int t_month = std::stoi(today.substr(5,2));
        int t_day = std::stoi(today.substr(8,2));
        int year = std::stoi(privacies[i].substr(0,4));
        int month = std::stoi(privacies[i].substr(5,2));
        int day = std::stoi(privacies[i].substr(8,2));
        int sum_today = t_year * 28 * 12 + t_month * 28 + t_day;
        int sum_chk = year * 28 * 12 + month * 28 + day;
        sum_chk += t[privacies[i][11]] * 28 - 1;
        if(sum_chk < sum_today)
            answer.push_back(i+1);
    }
    return answer;
}