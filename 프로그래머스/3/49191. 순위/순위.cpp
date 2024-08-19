#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int solution(int n, vector<vector<int>> results) 
{
    int dist[105][105];
    std::fill(&dist[0][0], &dist[104][105], INF);
    for(int i = 1; i <= n; i++)
        dist[i][i] = 0;
    for(const auto& iter : results)
    {
        dist[iter[0]][iter[1]] = 1;
        dist[iter[1]][iter[0]] = -1;
    }
    for(int mid = 1; mid <= n; mid++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(dist[i][mid] == INF || dist[mid][j] == INF)
                    continue;
                if(dist[i][mid] == 1 && dist[mid][j] == 1)
                {
                    dist[i][j] = 1;
                    dist[j][i] = -1;
                }
                if(dist[i][mid] == -1 && dist[mid][j] == -1)
                {
                    dist[i][j] = -1;
                    dist[j][i] = 1;
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
            if(dist[i][j] == INF)
                chk = false;
            //std::cout << dist[i][j] << ' ';
        }
        //std::cout <<'\n';
        if(chk)
            answer++;
    }
    
    return answer;
}