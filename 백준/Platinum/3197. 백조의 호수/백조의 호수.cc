/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
#define pii std::pair<int, int>
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int R, C, res;
bool vistied[1502][1502];
char arr[1502][1502];
std::queue<pii> q_s;
std::queue<pii> q_i;
std::vector<pii> swans;
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> R >> C;
    for(int r = 0; r < R; r++)
    {
        std::cin >> arr[r];
        for(int c = 0; c < C; c++)
        {
            if(arr[r][c] == '.' || arr[r][c] == 'L') q_i.push({r, c});
            if(arr[r][c] == 'L') swans.push_back({r, c});
        }
    }
    vistied[swans[0].first][swans[0].second] = true;
    q_s.push(swans[0]);
    while(vistied[swans[1].first][swans[1].second] == false)
    {
        int size_qi = q_i.size();
        for(int i = 0; i < size_qi; i++)
        {
            auto cur = q_i.front(); 
            q_i.pop();
            for(int dir = 0; dir < 4; dir++)
            {
                int ny = cur.first + dy[dir];
                int nx = cur.second + dx[dir];
                if(ny < 0 || nx < 0 || ny >= R || nx >= C || arr[ny][nx] != 'X') continue;
                q_i.push({ny, nx});
                arr[ny][nx] = '.';
            }
        }
        std::queue<pii> q_ns;
        while(q_s.size())
        {
            auto cur = q_s.front();
            q_s.pop();
            for(int dir = 0; dir < 4; dir++)
            {
                int ny = cur.first + dy[dir];
                int nx = cur.second + dx[dir];
                if(ny < 0 || nx < 0 || ny >= R || nx >= C || vistied[ny][nx]) continue;
                vistied[ny][nx] = true;
                if(arr[ny][nx] == '.' || arr[ny][nx] == 'L') q_s.push({ny, nx});
                else q_ns.push({ny, nx});
            }
        }
        q_s = q_ns;
        res++;
    }
    std::cout << res;
    return 0;
}
