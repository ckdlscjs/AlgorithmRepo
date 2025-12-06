#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int INF = 987654321;
int dist[4][26][26];
std::queue<std::tuple<int, int, int>> q;
int solution(vector<vector<int>> board) 
{
    std::fill_n(&dist[0][0][0], 4*26*26, INF);
    dist[0][0][0] = dist[1][0][0] = dist[2][0][0] = dist[3][0][0] = 0;
    q.push({0, 0, 0}); q.push({1, 0, 0}); q.push({2, 0, 0}); q.push({3, 0, 0});
    while(q.size())
    {
        int cd = std::get<0>(q.front());
        int cy = std::get<1>(q.front());
        int cx = std::get<2>(q.front());
        q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if(ny < 0 || nx < 0 || ny >= board.size() || nx >= board[0].size()) continue;
            int nxt_cost = dist[cd][cy][cx] + 1;
            if(cd < 2 && dir >= 2) nxt_cost += 5;
            if(cd >= 2 && dir < 2) nxt_cost += 5;
            if(board[ny][nx] || nxt_cost >= dist[dir][ny][nx]) continue;
            dist[dir][ny][nx] = nxt_cost;
            q.push({dir, ny, nx});
        }
    }
    return std::min({dist[0][board.size()-1][board[0].size()-1], dist[1][board.size()-1][board[0].size()-1], dist[2][board.size()-1][board[0].size()-1], dist[3][board.size()-1][board[0].size()-1]}) * 100;
}