/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int INF = 100 * 100 * 100 * 100 + 5;
int W, H, dists[4][102][102];
char arr[102][102];
std::queue<std::tuple<int, int, int>> q;
std::vector<std::pair<int, int>> SE;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> W >> H;
    for(int i = 0; i < H; i++)
    {
        std::cin >> arr[i];
        for(int j = 0; j < W; j++)
        {
            if(arr[i][j] == 'C')
            {
                SE.push_back({i, j});
            }
        }
    }
    std::fill_n(&dists[0][0][0], 4*102*102, INF);
    int sy = SE[0].first;
    int sx = SE[0].second;
    dists[0][sy][sx] = dists[1][sy][sx] = dists[2][sy][sx] = dists[3][sy][sx] = 0;
    for(int dir = 0; dir < 4; dir++)
    {
        for(int k = 1, ny = sy + dy[dir] * k, nx = sx + dx[dir] * k; 0 <= ny && ny < H && 0 <= nx && nx < W;)
        {
            if(arr[ny][nx] == '*') break;
            dists[dir][ny][nx] = 0;
            q.push({dir, ny, nx});
            k++;
            ny = sy + dy[dir] * k;
            nx = sx + dx[dir] * k;
        }
    }
    
    while(q.size())
    {
        auto cur = q.front();
        q.pop();
        int cd = std::get<0>(cur);
        int cy = std::get<1>(cur);
        int cx = std::get<2>(cur);
        //std::cout << cd << cy << cx << '\n';
        int dir = cd < 2 ? 2 : 0;
        for(int cnt = 0; cnt < 2; cnt++)
        {
            int nd = dir + cnt;
            for(int k = 1, ny = cy + dy[nd] * k, nx = cx + dx[nd] * k; 0 <= ny && ny < H && 0 <= nx && nx < W;)
            {
                if(arr[ny][nx] == '*' || dists[nd][ny][nx] <= dists[cd][cy][cx]) break;
                if(dists[nd][ny][nx] >= INF)
                {
                    dists[nd][ny][nx] = dists[cd][cy][cx] + 1;
                    q.push({nd, ny, nx});
                }
                k++;
                ny = cy + dy[nd] * k;
                nx = cx + dx[nd] * k;
            }
        }
        
    }
    
    int ey = SE[1].first;
    int ex = SE[1].second;
    std::cout << std::min({dists[0][ey][ex], dists[1][ey][ex], dists[2][ey][ex], dists[3][ey][ex]});
    return 0;
}
