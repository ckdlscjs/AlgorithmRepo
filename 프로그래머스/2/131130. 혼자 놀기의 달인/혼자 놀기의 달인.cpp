#include <bits/stdc++.h>

using namespace std;
int DFS(const std::vector<int>& card, std::vector<bool>& visited, int cur)
{
    if(visited[cur]) return 0;
    int ret = 1;
    visited[cur] = true;
    ret += DFS(card, visited, card[cur]-1);
    return ret;
}
int solution(vector<int> cards) 
{
    std::vector<int> cnts;
    std::vector<bool> visited(cards.size(), false);
    for(int i = 0; i < cards.size(); i++)
    {
        if(visited[i]) continue;
        cnts.push_back(DFS(cards, visited, i));
    }
    int answer = 0;
    std::sort(cnts.begin(), cnts.end());
    if(cnts.size() >= 2)
    {
        answer = cnts[cnts.size()-1] * cnts[cnts.size()-2];
    }
    return answer;
}