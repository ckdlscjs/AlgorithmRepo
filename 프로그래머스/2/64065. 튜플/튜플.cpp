#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    std::vector<std::vector<int>> arrays;
    std::vector<int> temps;
    std::string num;
    for(int i = 1; i < s.size() - 1; i++)
    {
        if(s[i] == '{')
        {
            temps.clear();
        }
            
        else if(s[i] == '}')
        {
            temps.push_back(std::stoi(num));
            num = "";
            arrays.push_back(temps);
        }
        else if(s[i] == ',' && num.size())
        {
            temps.push_back(std::stoi(num));
            num = "";
        }
        else if(s[i] == ',' && num.empty())
        {
            continue;
        }
        else
        {
            num += s[i];
        }
    }
    std::sort(arrays.begin(), arrays.end(), [](const std::vector<int>& a, const std::vector<int>& b)
              {
                  return a.size() < b.size();
              });
    std::set<int> chk;
    vector<int> answer;
    for(const auto& iter : arrays)
    {
        for(const auto& num : iter)
        {
            if(chk.find(num) == chk.end())
            {
                answer.push_back(num);
                chk.insert(num);
            }
        }
    }
    return answer;
}