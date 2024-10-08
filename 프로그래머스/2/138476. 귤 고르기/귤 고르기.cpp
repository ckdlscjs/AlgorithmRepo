#include <bits/stdc++.h>
using namespace std;
std::unordered_map<int, int> tanger;
std::priority_queue<std::pair<int, int> ,std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>> pq;
int solution(int k, vector<int> tangerine) 
{
    for(const auto& iter : tangerine)
        tanger[iter]++;
    for(const auto& iter : tanger)
        pq.push({iter.second, iter.first});
    int answer = 0;
    while(k > 0)
    {
        k -= pq.top().first;
        pq.pop();
        answer++;
    }
   
    return answer;
}