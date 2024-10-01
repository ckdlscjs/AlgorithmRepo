#include <bits/stdc++.h>
using namespace std;
std::unordered_map<std::string, int> idxs;
vector<string> solution(vector<string> players, vector<string> callings) 
{
    for(int i = 0; i < players.size(); i++)
        idxs[players[i]] = i;
    for(const auto& iter : callings)
    {
        int temp = idxs[iter];
        idxs[players[temp-1]]++;
        idxs[iter]--;
        players[temp] = players[temp-1];
        players[temp-1] = iter;
    }
    return players;
}