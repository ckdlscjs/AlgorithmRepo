#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};
int N, M, res = 11;
std::string str[12];
std::pair<int, int> r, b;
void Check(int cnt, std::pair<int, int> r, std::pair<int, int> b)
{
  if(cnt > 10) return;
  for(int dir = 0; dir < 4; dir++)
  {
    std::pair<int, int> tr = r;
    std::pair<int, int> tb = b;
    bool flagr = false;
    bool rnm = false;
    bool flagb = false;
    bool bnm = false;
    while(!flagb && !(rnm & bnm))
    {
      int nby = tb.first + dy[dir];
      int nbx = tb.second + dx[dir];
      int nry = tr.first + dy[dir];
      int nrx = tr.second + dx[dir];
      if(1 <= nry && nry < N-1 && 1 <= nrx && nrx < M-1)
      {
        if(str[nry][nrx] == '.')
        {
          str[nry][nrx] = 'R';
          str[tr.first][tr.second] = '.';
          tr.first = nry;
          tr.second = nrx;
        }
        else if(str[nry][nrx] == 'O')
        {
          str[tr.first][tr.second] = '.';
          rnm = true;
          flagr = true;
        }
      }
      if(str[nry][nrx] == 'B' || str[nry][nrx] == '#')
      {
        rnm = true;
      }
      if(1 <= nby && nby < N-1 && 1 <= nbx && nbx < M-1)
      {
        if(str[nby][nbx] == '.')
        {
          str[nby][nbx] = 'B';
          str[tb.first][tb.second] = '.';
          tb.first = nby;
          tb.second = nbx;
        }
        else if(str[nby][nbx] == 'O')
        {
          str[tb.first][tb.second] = '.';
          bnm = true;
          flagb = true;
        }
      }
      if(str[nby][nbx] == 'R' || str[nby][nbx] == '#')
      {
        bnm = true;
      }
    }
    if(flagb || flagr)
    {
      if(!flagb && flagr)
        res = std::min(res, cnt);
      str[r.first][r.second] = 'R';
      str[b.first][b.second] = 'B';
      if(tr.first != r.first || tr.second != r.second)
        str[tr.first][tr.second] = '.';
      if(tb.first != b.first || tb.second != b.second)
        str[tb.first][tb.second] = '.';
      continue;
    }
    Check(cnt + 1, tr, tb);
    str[r.first][r.second] = 'R';
    str[b.first][b.second] = 'B';
    if(tr.first != r.first || tr.second != r.second)
      str[tr.first][tr.second] = '.';
    if(tb.first != b.first || tb.second != b.second)
      str[tb.first][tb.second] = '.';
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int i = 0; i < N; i++)
  {
    std::cin >> str[i];
    for(int j = 0; j < str[i].size(); j++)
    {
      if(str[i][j] == 'R') r = std::make_pair(i, j);
      else if(str[i][j] == 'B') b = std::make_pair(i, j);
    }
  }
  Check(1, r, b);
  std::cout << (res >= 11 ? -1 : res);
  
  return 0;
}