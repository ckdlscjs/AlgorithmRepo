#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
std::vector<std::vector<int>> arr;
vector<int> solution(int rows, int columns, vector<vector<int>> queries) 
{
    arr.resize(rows, std::vector<int>());
    for(int i = 1; i <= rows; i++)
        for(int j = 1; j <= columns; j++)
            arr[i-1].push_back(j + (i-1) * columns);
    vector<int> answer;
    for(const auto& iter : queries)
    {
        int minval = rows * columns + 5;
        int ly = iter[0] - 1;
        int lx = iter[1] - 1;
        int ry = iter[2] - 1;
        int rx = iter[3] - 1;
        int sy = ly, sx = lx;
        int cur = arr[sy][sx];
        int dir = 0;
        while(dir < 4)
        {
            int ny = sy + dy[dir];
            int nx = sx + dx[dir];
            if(ny < ly || ny > ry || nx < lx || nx > rx)
            {
                dir++;
                continue;
            }
            int c = arr[sy][sx];
            arr[sy][sx] = cur;
            cur = c;
            minval = std::min(minval, cur);
            sy = ny;
            sx = nx;
        }
        arr[sy][sx] = cur;
        /*
        for(int i = 1; i <= rows; i++)
        {
            for(int j = 1; j <= columns; j++)
            {
                std::cout << arr[i-1][j-1] << ' ';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
        */    
        answer.push_back(minval);
    }
    return answer;
}