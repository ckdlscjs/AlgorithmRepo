#include <bits/stdc++.h>
using namespace std;
const int MaxN = 55;
std::unordered_map<std::string, int> index_fr;
int checks[MaxN][MaxN];
std::unordered_map<std::string, std::pair<int, int>> trade;
std::unordered_map<std::string, int> score;
std::unordered_map<std::string, int> result;

int solution(vector<string> friends, vector<string> gifts) 
{
    for(int i = 0; i < friends.size(); i++)
    {
        trade[friends[i]] = {0, 0};
        index_fr[friends[i]] = i;
        score[friends[i]] = 0;
        result[friends[i]] = 0;
    }
        
    for(const auto& str : gifts)
    {
        std::string name[2];
        int str_idx = 0;
        for(const auto& ch : str)
        {
            if(ch == ' ')
            {
                str_idx++;
                continue;
            }
            name[str_idx] += ch;
        }
        trade[name[0]].first++;
        trade[name[1]].second++;
        checks[index_fr[name[0]]][index_fr[name[1]]]++;
    }
    for(const auto& iter : trade)
    {
        score[iter.first] = iter.second.first - iter.second.second;
    }
    int answer = 0;
    for(int i = 0; i < friends.size(); i++)
    {
        for(int j = i+1; j < friends.size(); j++)
        {
            if(checks[i][j] || checks[j][i])
            {
                result[friends[i]] += checks[i][j] > checks[j][i] ? 1 : 0;
                result[friends[j]] += checks[j][i] > checks[i][j] ? 1 : 0;
            }
            if(!checks[i][j] && !checks[j][i] || checks[i][j] == checks[j][i])
            {
                result[friends[i]] += score[friends[i]] > score[friends[j]] ? 1 : 0;
                result[friends[j]] += score[friends[j]] > score[friends[i]] ? 1 : 0;
            }
        }
    }
    for(const auto& iter : result)
    {
        answer = std::max(answer, iter.second);
    }
    return answer;
}