#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) 
{
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    for(int i = 0; i < rank.size(); i++)
        if(attendance[i])
            pq.push(std::make_pair(rank[i], i));
    int a = pq.top().second;
    pq.pop();
    int b = pq.top().second;
    pq.pop();
    int c = pq.top().second;
    std::cout << a << ' ' << b << ' ' << c;
    return (10000*a) + (100*b) + c;
}