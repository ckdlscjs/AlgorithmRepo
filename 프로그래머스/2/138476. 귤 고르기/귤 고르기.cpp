#include <bits/stdc++.h>
using namespace std;
std::unordered_map<int, int> cnts;
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>> pq;
int solution(int k, vector<int> arr) 
{
    for(const auto& iter : arr)
        cnts[iter]++;
    for(const auto& iter : cnts)
    {
        //std::cout << iter.first << ' ' << iter.second << '\n';
        pq.push({iter.second, iter.first});
    }
        
    int answer = 0;
    while(k > 0)
    {
        k -= pq.top().first;
        pq.pop();
        answer++;
    }
    return answer;
}