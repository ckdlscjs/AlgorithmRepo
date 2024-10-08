#include <bits/stdc++.h>
using namespace std;
int cur, idx, t = 1;
int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    std::queue<std::pair<int, int>> q;
    while(t)
    {
        if(q.size() && t > q.front().first)
        {
            cur -= q.front().second;
            q.pop();
            if(idx >= truck_weights.size() && q.empty())
                break;
        }
        if(idx < truck_weights.size() && cur + truck_weights[idx] <= weight)
        {
            cur += truck_weights[idx];
            //std::cout << t << '\n';
            q.push({t + bridge_length-1,truck_weights[idx++]});
        }
        //std::cout << t << ":"<<(q.size() ? q.front().second : 0) <<'\n';
        t++;
    }
    return t;
}