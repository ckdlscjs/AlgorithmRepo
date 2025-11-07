#include <bits/stdc++.h>
using namespace std;
const int dy[] = {1, 0, -1};
const int dx[] = {0, 1, -1};
int dir;
vector<int> solution(int n) 
{
    std::vector<int> answer;
    answer.resize(n * (n+1) / 2, 0);
    int y = 0, x = 0, num = 1;
    
    for(int i = n; i >= 1; i--)
    {
        for(int j = 0; j < i-1; j++)
        {
            int idx = y * n + x;
            for(int diff = 0; diff < y; diff++)
                idx -= (n-(diff+1));
            answer[idx] = num++;
            y += dy[dir];
            x += dx[dir];
        }
        int idx = y * n + x;
        for(int diff = 0; diff < y; diff++)
            idx -= (n-(diff+1));
        answer[idx] = num++;
        dir++;
        dir%=3;
        y += dy[dir];
        x += dx[dir];
    }
    
    return answer;
}