#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    std::queue<std::pair<int, int>> q;
    int answer = 1;
    int curcnt = 0;
    int curweight = 0;
    for(const auto& iter : truck_weights)
    {
        while(q.size() && (curcnt + 1 > bridge_length || curweight + iter > weight))
        {
            answer = std::max(answer, q.front().first);
            curweight -= q.front().second;
            q.pop();
            curcnt -= 1;
        }
        q.push({answer + bridge_length, iter});
        std::cout << answer << ' ' << iter << '\n';
        curcnt += 1;
        curweight += iter;
        answer++;
    }
    while(q.size())
    {
        answer = q.front().first;
        q.pop();
    }
    return answer;
}