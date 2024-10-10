#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};
int N, x, y, d, g, res;
bool arr[105][105];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    std::cin >> x >> y >> d >> g;
    std::vector<int> st;
    arr[y][x] = true;
    y += dy[d];
    x += dx[d];
    arr[y][x] = true;
    st.push_back((d+1)%4);
    for(int j = 1; j <= g; j++)
    {
      for(int idx = st.size()-1; idx >= 0; idx--)
      {
        y += dy[st[idx]];
        x += dx[st[idx]];
        arr[y][x] = true;
        st.push_back((st[idx]+1)%4);
      }
    }
  }
  for(int i = 1; i < 105; i++)
    for(int j = 1; j < 105; j++)
      res += arr[i-1][j-1] & arr[i-1][j] & arr[i][j-1] & arr[i][j] ? 1 : 0;
  std::cout << res;
  return 0;
}