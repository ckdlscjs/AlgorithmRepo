#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> players, int m, int k) 
{  
    int answer = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> servers;
    for(int i = 0; i < players.size(); i++)
    {
        while(servers.size() && servers.top() < i) servers.pop();
        if(players[i] / m > servers.size())
        {
            int cnt = (players[i] / m) - servers.size();
            answer += cnt;
            for(int j = 0; j < cnt; j++) servers.push(i + k - 1);
        }
    }
    return answer;
}