#include <bits/stdc++.h>
using namespace std;
int cur, t, idx;
int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    std::queue<std::pair<int, int>> q;
    t = 1;
    while(1)
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