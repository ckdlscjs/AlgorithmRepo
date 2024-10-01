#include <bits/stdc++.h>
using namespace std;
std::unordered_map<std::string, int> nyscore;
vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) 
{
    for(int i = 0; i < name.size(); i++)
        nyscore[name[i]] = yearning[i];
    std::vector<int> answer;
    for(const auto& iter : photo)
    {
        int sum = 0;
        for(const auto& vecit : iter)
            sum += nyscore[vecit];
        answer.push_back(sum);
    }
    return answer;                                     
}