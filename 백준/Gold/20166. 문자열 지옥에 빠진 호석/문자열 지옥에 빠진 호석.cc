#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int N, M, K;
std::string str;
char arr[11][11];
std::unordered_map<std::string, int> cnts;
void DFS(int y, int x, std::string s)
{
  cnts[s]++;
  if(s.size() >= 5) return;
  for(int dir = 0; dir < 8; dir++)
  {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(ny >= N) ny %= N;
    else if(ny < 0) ny += N;
    if(nx >= M) nx %= M;
    else if(nx < 0) nx += M;
    DFS(ny, nx, s + arr[ny][nx]);
  }
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M >> K;
  for(int n = 0; n < N; n++)
  {
    std::cin >> str;
    for(int m = 0; m < M; m++) arr[n][m] = str[m];
  }
  for(int n = 0; n < N; n++)
    for(int m = 0; m < M; m++)
      DFS(n, m, std::string(1, arr[n][m]));
  for(int k = 0; k < K; k++)
  {
    std::cin >> str;
    std::cout << cnts[str] <<'\n';
  }
  return 0;
}