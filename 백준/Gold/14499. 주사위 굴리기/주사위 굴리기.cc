#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};
int N, M, y, x, K, d;
int arr[22][22], dice[6];
void Move(int dir, int y, int x)
{
  int newdice[6];
  if(dir == 1)
  {
    newdice[0] = dice[3];
    newdice[1] = dice[1];
    newdice[2] = dice[0];
    newdice[3] = dice[5];
    newdice[4] = dice[4];
    newdice[5] = dice[2];
  }
  else if(dir == 2)
  {
    newdice[0] = dice[2];
    newdice[1] = dice[1];
    newdice[2] = dice[5];
    newdice[3] = dice[0];
    newdice[4] = dice[4];
    newdice[5] = dice[3];
  }
  else if(dir == 3)
  {
    newdice[0] = dice[4];
    newdice[1] = dice[0];
    newdice[2] = dice[2];
    newdice[3] = dice[3];
    newdice[4] = dice[5];
    newdice[5] = dice[1];
  }
  else
  {
    newdice[0] = dice[1];
    newdice[1] = dice[5];
    newdice[2] = dice[2];
    newdice[3] = dice[3];
    newdice[4] = dice[0];
    newdice[5] = dice[4];
  }
  if(arr[y][x] == 0)
  {
    arr[y][x] = newdice[5];
  }
  else
  {
    newdice[5] = arr[y][x];
    arr[y][x] = 0;
  }
  for(int i = 0; i < 6; i++)
    dice[i] = newdice[i];
  std::cout << dice[0] << '\n';
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M >> y >> x >> K;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      std::cin >> arr[i][j];
  for(int k = 0; k < K; k++)
  {
    std::cin >> d;
    int ny = y + dy[d-1];
    int nx = x + dx[d-1];
    if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
    y = ny;
    x = nx;
    Move(d, ny, nx);
  }
  return 0;
}