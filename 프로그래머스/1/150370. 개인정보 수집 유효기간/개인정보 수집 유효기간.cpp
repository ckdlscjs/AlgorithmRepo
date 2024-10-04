#include <bits/stdc++.h>
using namespace std;
std::unordered_map<char, int> t;
vector<int> solution(string today, vector<string> terms, vector<string> privacies) 
{
    for(const auto& iter : terms)
        t[iter[0]] = std::stoi(iter.substr(2));
    vector<int> answer;
    //std::cout << iter.substr(0,4) << iter.substr(5,2) << iter.substr(8,2) <<'\n';
    for(int i = 0; i < privacies.size(); i++)
    {
        std::string chk = privacies[i].substr(0,10);
        int year = std::stoi(chk.substr(0,4));
        int month = std::stoi(chk.substr(5,2));
        int day = std::stoi(chk.substr(8,2));
        for(int j = 0; j < t[privacies[i][11]]; j++)
        {
            day += j == 0 ? 27 : 28;
            if(day > 28)
            {
                day -= 28;
                month += 1;
                if(month > 12)
                {
                    month -= 12;
                    year += 1;
                }
            }
        }
        int t_year = std::stoi(today.substr(0,4));
        int t_month = std::stoi(today.substr(5,2));
        int t_day = std::stoi(today.substr(8,2));
        int sum_chk = year*12*28 + month*28 + day;
        int sum_today = t_year*12*28 + t_month*28 + t_day;
        if(sum_chk < sum_today)
            answer.push_back(i+1);
    }
    return answer;
}