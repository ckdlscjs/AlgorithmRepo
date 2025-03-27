#include <bits/stdc++.h>
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int N, M, K, visited[12][12], val;
std::vector<std::pair<int, std::pair<int, int>>> inputs;
bool chkdir(int y, int x)
{
    if(visited[y][x]) return false;
    for(int dir = 0; dir < 4; dir++)
    {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if(visited[ny][nx]) return false;
    }
    return true;
}
int Check(int cur, int idx, int sum)
{
    if(cur >= K) return sum;
    int ret = -1'000'000;
    for(int i = idx; i < inputs.size(); i++)
    {
        int y = inputs[i].second.first;
        int x = inputs[i].second.second;
        if(!chkdir(y, x)) continue;
        visited[y][x] = true;
        ret = std::max(ret, Check(cur+1, i+1, sum + inputs[i].first));
        visited[y][x] = false;
    }
    return ret;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> K;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            std::cin >> val;
            inputs.push_back({val, {i, j}});
        }
    }
    std::cout << Check(0,0,0);
    return 0;
}