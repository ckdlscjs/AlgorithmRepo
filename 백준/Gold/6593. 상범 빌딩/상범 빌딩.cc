#include <bits/stdc++.h>
const int dl[] = {0, 0, 0, 0, -1, 1};
const int dr[] = {0, 0, 1, -1, 0, 0};
const int dc[] = {1, -1, 0, 0, 0, 0};
int L, R, C, sl, sr, sc, el, er, ec, dist[35][35][35];
std::string building[35][35];
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  while(std::cin >> L >> R >> C && (L|R|C) != 0)
  {
    std::memset(dist, 0, sizeof(dist));
    for(int l = 0; l < L; l++)
    {
      for(int r = 0; r < R; r++)
      {
        std::cin >> building[l][r];
        if(building[l][r].find('S') != std::string::npos)
        {
          sl = l;
          sr = r;
          sc = building[l][r].find('S');
        }
        if(building[l][r].find('E') != std::string::npos)
        {
          el = l;
          er = r;
          ec = building[l][r].find('E');
        }
      }
    }
    std::queue<std::pair<int, std::pair<int, int>>> q;
    q.push({sl,{sr, sc}});
    dist[sl][sr][sc] = 1;
    while(q.size())
    {
      int cl = q.front().first;
      int cr = q.front().second.first;
      int cc = q.front().second.second;
      q.pop();
      for(int dir = 0; dir < 6; dir++)
      {
        int nl = cl + dl[dir];
        int nr = cr + dr[dir];
        int nc = cc + dc[dir];
        if(nl < 0 || nr < 0 || nc < 0 || nl >= L || nr >= R || nc >= C || dist[nl][nr][nc] || building[nl][nr][nc] == '#') continue;
        dist[nl][nr][nc] = dist[cl][cr][cc] + 1;
        q.push({nl, {nr, nc}});
      }
    }
    if(dist[el][er][ec])
      std::cout << "Escaped in " <<  dist[el][er][ec] -1 << " minute(s)." << '\n';
    else
      std::cout << "Trapped!" << '\n';
  }
  return 0;
}