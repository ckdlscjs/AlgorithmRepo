#include <bits/stdc++.h>

using namespace std;
using pii = std::pair<int, int>;
std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq_small;
std::priority_queue<pii, std::vector<pii>, std::less<pii>> pq_large;
bool dels[1'000'002];
vector<int> solution(vector<string> oper) 
{
    int cnt = 0;
    for(int i = 0; i < oper.size(); i++)
    {
        int num = std::stoi(oper[i].substr(2));
        if(oper[i][0] == 'I')
        {
            pq_small.push({num, i});
            pq_large.push({num, i});
            cnt++;
        }
        else
        {
            if(cnt <= 0) continue;
            cnt--;
            if(num == 1)
            {
                while(pq_large.size() && dels[pq_large.top().second])
                    pq_large.pop();
                dels[pq_large.top().second] = true;
                pq_large.pop();
            }
            else
            {
                
                while(pq_small.size() && dels[pq_small.top().second])
                    pq_small.pop();
                dels[pq_small.top().second] = true;
                pq_small.pop();
            }
        }
    }
    while(pq_large.size() && dels[pq_large.top().second])
                    pq_large.pop();
    while(pq_small.size() && dels[pq_small.top().second])
                    pq_small.pop();
    if(cnt <= 0) return {0, 0};
    return {pq_large.top().first, pq_small.top().first};
}