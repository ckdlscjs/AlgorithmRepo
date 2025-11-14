#include <bits/stdc++.h>

using namespace std;
std::unordered_set<int> chks;
void Check(const std::vector<std::string>& users, const std::vector<std::string>& bans, int idx, int mask)
{
    if(idx >= bans.size())
    {
        chks.insert(mask);
    }
    else
    {
        for(int i = 0; i < users.size(); i++)
        {
            if(mask & (1 << i)) continue;
            if(bans[idx].size() != users[i].size()) continue;
            int j = 0;
            for(j = 0; j < bans[idx].size(); j++)
            {
                if(bans[idx][j] == users[i][j] || bans[idx][j] == '*') continue;
                break;
            }
            if(j == bans[idx].size())
                Check(users, bans, idx+1, mask | (1 << i));
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) 
{
    Check(user_id, banned_id, 0, 0);
    return chks.size();
}