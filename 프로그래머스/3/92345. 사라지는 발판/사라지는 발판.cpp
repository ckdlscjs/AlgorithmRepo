#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int check(std::vector<std::vector<int>>& boards, std::vector<int> cur, std::vector<int> next)
{
    if(!boards[cur[0]][cur[1]])
        return 0;
    int beststep = 0;
    for(int dir = 0; dir < 4; dir++)
    {
        int ny = dy[dir] + cur[0];
        int nx = dx[dir] + cur[1];
        if(ny < 0 || nx < 0 || ny >= boards.size() || nx >= boards[0].size() || !boards[ny][nx])
            continue;
        boards[cur[0]][cur[1]] = 0;
        int step = check(boards, next, {ny, nx}) + 1;
        boards[cur[0]][cur[1]] = 1;
        
        if(beststep % 2 == 0 && step % 2 == 1)
            beststep = step;
        else if(beststep % 2 == 0 && step % 2 == 0)
            beststep = std::max(beststep, step);
        else if(beststep % 2 == 1 && step % 2 == 1)
            beststep = std::min(beststep, step);
    }
    return beststep;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) 
{
    return check(board, aloc, bloc);
}