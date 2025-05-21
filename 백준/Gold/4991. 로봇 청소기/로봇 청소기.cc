#include <bits/stdc++.h>
using namespace std;
using pii = std::pair<int, int>;
using tiii = std::tuple<int, int, int>;
const int INF = 987654321;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int w, h;
char str[22];
char arr[22][22];
int dist[12][22][22], dp[1<<12][12];
int Check(const std::vector<pii>& poss, int mask, int cur)
{
    if(mask == (1 << poss.size()) - 1) return 0;
    int& ret = dp[mask][cur];
    if(ret != -1) return ret;
    ret = INF;
    for(int i = 1; i < poss.size(); i++)
    {
        if(mask & (1 << i)) continue;
        ret = std::min(ret, Check(poss, mask | (1 << i), i) + dist[cur][poss[i].first][poss[i].second]-1);
    }
    return ret;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(std::cin >> w >> h)
    {
        if(w == 0 && h == 0) return 0;
        int cnts = 0;
        std::memset(dp, -1, sizeof(dp));
        std::memset(dist, 0, sizeof(dist));
        std::vector<pii> poss(1);
        for(int i = 0; i < h; i++)
        {
            std::cin >> str;
            for(int j = 0; j < w; j++)
            {
                arr[i][j] = str[j];
                if(arr[i][j] == 'o')  poss[0] = std::make_pair(i, j);
                else if(arr[i][j] == '*') poss.push_back(std::make_pair(i, j));
            }
        }
        std::queue<tiii> q;
        for(int i = 0; i < poss.size(); i++)
        {
            dist[i][poss[i].first][poss[i].second] = 1;
            q.push({i, poss[i].first, poss[i].second});
        }
        while(q.size())
        {
            auto cur = q.front(); q.pop();
            int ci = std::get<0>(cur);
            int cy = std::get<1>(cur);
            int cx = std::get<2>(cur);
            if(ci == 0 && arr[cy][cx] == '*') 
                cnts++;
            for(int dir = 0; dir < 4; dir++)
            {
                int ny = cy + dy[dir];
                int nx = cx + dx[dir];
                if(ny < 0 || nx < 0 || ny >= h || nx >= w || dist[ci][ny][nx] || arr[ny][nx] == 'x') continue;
                q.push({ci, ny, nx});
                dist[ci][ny][nx] = dist[ci][cy][cx] + 1;
            }
        }
        if(cnts+1 < poss.size())
        {
            std::cout << -1 << '\n';
            continue;
        }
        /*
        for(int i = 0; i < poss.size(); i++)
        {
            for(int j = 0; j < poss.size(); j++)
            {
                std::cout << dist[i][poss[j].first][poss[j].second] << ' ';
            }
            std::cout << '\n';
        }
        std::cout << (1<<poss.size())-1 << '\n';
        */
        std::cout << Check(poss, 1, 0) << '\n';
    }
    return 0;
}
