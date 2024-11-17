//https://school.programmers.co.kr/learn/courses/30/lessons/92345
#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int Check(std::vector<std::vector<int>>& board, std::vector<int> cur, std::vector<int> nxt)
{
    int beststep = 0;
    if(board[cur[0]][cur[1]] == 0) return beststep; //탐색할곳이 없다면 패배이므로 0
    for(int dir = 0; dir < 4; dir++)
    {
        int ny = cur[0] + dy[dir];
        int nx = cur[1] + dx[dir];
        if(ny < 0 || nx < 0 || ny >= board.size() || nx >= board[0].size() || board[ny][nx] == 0) continue;
        board[cur[0]][cur[1]] = 0;
        int step = Check(board, nxt, {ny, nx}) + 1; //이동을 한번은 진행 하였으므로 + 1
        board[cur[0]][cur[1]] = 1;
        
        if(beststep % 2 == 0 && step % 2 == 1) //현재 이동의 결과가 이기는횟수, 최선결과가 지는횟수면 갱신
            beststep = step;
        else if(beststep % 2 == 0 && step % 2 == 0) //둘다 지는조건이라면 최대한 이동횟수를늘린다
            beststep = std::max(beststep, step);
        else if(beststep % 2 == 1 && step % 2 == 1) //둘다 이기는 조건이라면 최소한으로 이동한다
            beststep = std::min(beststep, step);
    }
    return beststep;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) 
{
    return Check(board, aloc, bloc);
}