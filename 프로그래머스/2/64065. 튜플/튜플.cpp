#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) 
{
    std::string num;
    int counts[100005];
    std::memset(counts, 0, sizeof(counts));
    std::unordered_set<int> chks;
    vector<int> answer;
    for(const auto& iter : s)
    {
        if('0' <= iter && iter <= '9')
        {
            num += iter;
        }
        else
        {
            if(num.size())
            {
                int val = std::stoi(num);
                counts[val]++;
                chks.insert(val);
                num.clear();
            }
        }
    }
    for(const auto& iter : chks)
        answer.push_back(iter);
    std::sort(answer.begin(), answer.end(), [=](const int& a, const int& b)
              {
                  return counts[a] > counts[b];
              });
    return answer;
}