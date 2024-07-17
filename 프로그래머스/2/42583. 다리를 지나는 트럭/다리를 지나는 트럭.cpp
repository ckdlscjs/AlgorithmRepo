#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int answer = 1;
    int idx = 0;
    int cur_weight = 0;
    std::queue<std::pair<int, int>> q;
    do
    {
        if(q.size() && answer >= q.front().first)
        {
            cur_weight -= q.front().second;
            std::cout << answer << ':' << q.front().second <<'\n';
            q.pop();
        }
        if(idx < truck_weights.size() && cur_weight + truck_weights[idx] <= weight)
        {
            q.push({answer + bridge_length, truck_weights[idx]});
            cur_weight += truck_weights[idx++];
        }
        answer++;
    }while(q.size());
    return answer-1;
}