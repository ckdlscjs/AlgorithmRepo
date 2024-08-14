#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int costs[27][27][4];
int solution(vector<vector<int>> board) 
{
    costs[0][0][0] = 1;
    costs[0][0][2] = 1;
    std::queue<std::pair<std::pair<int,int>, int>> q;
    q.push({{0, 0}, 0});
    q.push({{0, 0}, 2});
    while(q.size())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cur = q.front().second;
        
        q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny < 0 || nx < 0 || ny >= board.size() || nx >= board.size() || board[ny][nx])
                continue;
            int corner = 0;
            if((cur < 2 && dir >= 2) || (cur >= 2 && dir < 2))
                corner += 5;
            if(!costs[ny][nx][dir] || costs[y][x][cur] + 1 + corner < costs[ny][nx][dir])
            {
                costs[ny][nx][dir] = costs[y][x][cur] + 1 + corner;
                q.push({{ny,nx},dir});
                //std::cout << ny << ","<<nx<<":"<<dir <<" " << costs[ny][nx][dir] <<'\n';
            }
        }
    }
    int answer = 987654321;
    for(int dir = 0; dir < 4; dir++)
        if(!costs[board.size()-1][board.size()-1][dir])
            continue;
        else
            answer = std::min(costs[board.size()-1][board.size()-1][dir], answer);
    return (answer - 1) * 100;
}