#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> players, int m, int k) 
{
    int answer = 0;
    std::queue<int> servers;
    for(int i = 0; i < players.size(); i++)
    {
        while(servers.size() && i >= servers.front())
        {
            servers.pop();
        }
        if(players[i] >= (servers.size() + 1) * m)
        {
            int need = players[i] / m - servers.size();
            answer += need;
            for(int j = 0; j < need; j++)
                servers.push(i + k);
        }
    }
    
    return answer;
}