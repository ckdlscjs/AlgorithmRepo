#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> array) 
{
    std::map<int, int> input;
    for(const auto& num : array)
        input[num]++;
    
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>> pq;
    for(const auto& iter : input)
    {
        pq.push(std::make_pair(iter.second, iter.first));
    }
    std::pair<int, int> output[2];
    output[0] = pq.top();
    pq.pop();
    output[1] = pq.top();
    
    int answer = output[0].first != output[1].first ? output[0].second : output[0].second != output[1].second ? -1 : output[0].second;
    return answer;
}