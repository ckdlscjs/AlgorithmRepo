#include <bits/stdc++.h>
using namespace std;
int result = 0;
bool check_cross(std::vector<std::vector<int>>& chess, int y, int x)
{
    for(int i = 0; i < chess.size(); i++)
    {
        if((chess[y][i] && i != x) || (chess[i][x] && i != y))
            return false;
    }
    return true;
}
const int diagonal_y[] = {-1, -1, 1, 1};
const int diagonal_x[] = {-1 ,1 ,-1, 1};
bool check_diagonal(std::vector<std::vector<int>>& chess, int y, int x, int dir)
{
    if(y < 0 || x < 0 || y >= chess.size() || x >= chess.size())
       return true;
    if(chess[y][x])
        return false;
    return check_diagonal(chess, y + diagonal_y[dir], x + diagonal_x[dir], dir);
}
void check(std::vector<std::vector<int>>& chess, int cnt)
{
    if(cnt >= chess.size())
    {
        result++;
        return;
    }
    for(int j = 0; j < chess.size(); j++)
    {
        if(chess[cnt][j])
            continue;
        chess[cnt][j] = 1;
        if(
            check_cross(chess, cnt, j) && 
            check_diagonal(chess, cnt + diagonal_y[0], j + diagonal_x[0], 0) &&
            check_diagonal(chess, cnt + diagonal_y[1], j + diagonal_x[1], 1) &&
            check_diagonal(chess, cnt + diagonal_y[2], j + diagonal_x[2], 2) &&
            check_diagonal(chess, cnt + diagonal_y[3], j + diagonal_x[3], 3))
                check(chess, cnt+1);
            
        chess[cnt][j] = 0;
    }
}
int solution(int n) 
{
    std::vector<std::vector<int>> chess(n, std::vector<int>(n, 0));
    check(chess, 0);
    return result;
}