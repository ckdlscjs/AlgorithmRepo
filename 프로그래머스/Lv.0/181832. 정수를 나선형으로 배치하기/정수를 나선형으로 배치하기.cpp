#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
const int MaxN = 35;
int arr[MaxN][MaxN];
vector<vector<int>> solution(int n) 
{
    int idx = 1;
    int dir = 0;
    int y = 0, x = 0;
    while(idx <= n*n)
    {
        if(y >= 0 && y < n && x >= 0 && x < n && !arr[y][x])
        {
            arr[y][x] = idx++;
            y += dy[dir];
            x += dx[dir];
        }
        else
        {
            y -= dy[dir];
            x -= dx[dir];
            dir++;
            if(dir >= 4)
                dir = 0;
            y += dy[dir];
            x += dx[dir];
        }
    }
    
    std::vector<std::vector<int>> answer;
    for(int i = 0; i < n; i++)
    {
        std::vector<int> input_j;
        for(int j = 0; j < n; j++)
        {
            input_j.push_back(arr[i][j]);
            std::cout << arr[i][j] << ' ';
        }
        std::cout <<'\n';
        answer.push_back(input_j);
    }
    
    return answer;
}