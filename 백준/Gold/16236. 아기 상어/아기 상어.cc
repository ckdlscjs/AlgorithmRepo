#include <bits/stdc++.h>
using namespace std;
using tiii = std::tuple<int, int, int>;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int N, arr[22][22], cnt, res, dist[22][22];
tiii bshark;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cin >> arr[i][j];
            if(arr[i][j] == 9)
            {
                std::get<0>(bshark) = 2;
                std::get<1>(bshark) = i;
                std::get<2>(bshark) = j;
                arr[i][j] = 0;
            }
        }
    }
    while(1)
    {
        std::queue<std::pair<int, int>> q;
        int sw = std::get<0>(bshark);
        int sy = std::get<1>(bshark);
        int sx = std::get<2>(bshark);
        q.push({sy, sx});
        dist[sy][sx] = 1;
        while(q.size())
        {
            int cy = q.front().first;
            int cx = q.front().second;
            q.pop();
            for(int dir = 0; dir < 4; dir++)
            {
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];
                if(ny < 0 || nx < 0 || ny >= N || nx >= N || dist[ny][nx] || arr[ny][nx] > sw) continue;
                q.push({ny, nx});
                dist[ny][nx] = dist[cy][cx] + 1;
            }
        }
        std::vector<tiii> fishes;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(arr[i][j] == 0 || dist[i][j] == 0 || arr[i][j] >= sw) continue;
                fishes.push_back({dist[i][j], i, j});
            }
        }
        if(fishes.empty())
            break;
        std::sort(fishes.begin(), fishes.end(), [](const tiii& a, const tiii& b)->bool{
            int aw = std::get<0>(a);
            int ai = std::get<1>(a);
            int aj = std::get<2>(a);
            int bw = std::get<0>(b);
            int bi = std::get<1>(b);
            int bj = std::get<2>(b);
            if(aw == bw)
            {
                if(ai == bi)
                {
                    return aj < bj;
                }
                return ai < bi;
            }
            return aw < bw;
        });
        arr[std::get<1>(fishes[0])][std::get<2>(fishes[0])] = 0;
        res += std::get<0>(fishes[0]) - 1;
        cnt++;
        if(cnt >= sw)
        {
            cnt = 0;
            sw++;
        }
        std::get<0>(bshark) = sw;
        std::get<1>(bshark) = std::get<1>(fishes[0]);
        std::get<2>(bshark) = std::get<2>(fishes[0]);
        std::memset(dist, 0, sizeof(dist));
    }
    std::cout << res;
    return 0;
}
