#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> array, int n) {
    std::priority_queue<std::pair<int,int>,  std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    for(const auto& num : array)
        pq.push({std::abs(num - n), num});
    return pq.top().second;
}