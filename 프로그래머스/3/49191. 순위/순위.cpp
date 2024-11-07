//https://school.programmers.co.kr/learn/courses/30/lessons/49191
#include <bits/stdc++.h>
using namespace std;
int costs[105][105];
int solution(int n, vector<vector<int>> results) 
{
    for(const auto& iter : results)
    {
        costs[iter[1]][iter[0]] = 1;
        costs[iter[0]][iter[1]] = -1;
    }
    for(int m = 1; m <= n; m++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(!costs[i][m]) continue;
                if(costs[i][m] == 1 && costs[m][j] == 1)
                {
                    costs[i][j] = 1;
                    costs[j][i] = -1;
                }
                else if(costs[i][m] == -1 && costs[m][j] == -1)
                {
                    costs[i][j] = -1;
                    costs[j][i] = 1;
                }
            }
        }
    }     
    int answer = 0;
    for(int i = 1; i <= n; i++)
    {
        bool chk = true;
        for(int j = 1; j <= n; j++)
        {
            if(i == j) continue;
            if(!costs[i][j]) chk = false;
        }
        if(chk) answer++;
    }
    return answer;
}