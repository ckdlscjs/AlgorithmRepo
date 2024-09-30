#include <bits/stdc++.h>
using namespace std;
const int MaxN = 55;
std::unordered_map<std::string, int> idxs;
int gifts_arr[MaxN][MaxN];
std::pair<int, int> gifts_value[MaxN];
int solution(vector<string> friends, vector<string> gifts) 
{
    for(int i = 0; i < friends.size(); i++)
        idxs[friends[i]] = i;
    
    for(const auto& iter : gifts)
    {
        int it = iter.find(' ');
        std::string s = iter.substr(0, it);
        std::string r = iter.substr(it+1);
        gifts_arr[idxs[s]][idxs[r]]++;
        gifts_value[idxs[s]].first++;
        gifts_value[idxs[r]].second++;
    }
    int answer = 0;
    for(int i = 0; i < friends.size(); i++)
    {
        int u = idxs[friends[i]];
        int res = 0;
        for(int j = 0; j < friends.size(); j++)
        {
            if(i == j)
                continue;
            int v = idxs[friends[j]];
            if(gifts_arr[u][v] > gifts_arr[v][u])
                res++;
            if(gifts_arr[u][v] == gifts_arr[v][u] && gifts_value[u].first - gifts_value[u].second > gifts_value[v].first - gifts_value[v].second)
                res++;
        }
        answer = std::max(answer, res);
    }
    
    return answer;
}