#include <bits/stdc++.h>

using namespace std;
std::map<int, int> cnts;
void Check(const std::string& str, const int length, int cur, int idx, int mask)
{
    if(cur >= length)
    {
        cnts[mask]++;
        return;
    }
    for(int i = idx; i < str.size(); i++)
    {
        Check(str, length, cur+1, i+1, mask | 1 << (str[i] - 'A'));
    }
}
vector<string> solution(vector<string> orders, vector<int> course) 
{
    vector<string> answer;
    for(const auto& iter : orders)
    {
        for(const auto& cnt : course)
        {
            Check(iter, cnt, 0, 0, 0);
        }
    }
    std::map<int, std::vector<std::pair<int, std::string>>> results;
    for(const auto& iter : cnts)
    {
        std::string str;
        for(int i = 0; i < 26; i++)
        {
            if(iter.first & (1 << i))
            str += std::string(1, (char)i + 'A');
        }
        results[str.size()].push_back({iter.second, str});
    }
    
    
    for(auto& iter : results)
    {
        std::sort(iter.second.begin(), iter.second.end(), [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
           return a.first > b.first; 
        });
        
        for(int i = 0; i < iter.second.size() && iter.second[i].first >= 2 && iter.second[i].first == iter.second[0].first; i++)
        {
            answer.push_back(iter.second[i].second);
        }
    }
    std::sort(answer.begin(), answer.end());
    return answer;
}