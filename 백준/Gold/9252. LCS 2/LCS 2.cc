#include <bits/stdc++.h>
std::string str1;
std::string str2;
int dp[1005][1005], len;
std::pair<int, int> pos;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> str1 >> str2;
  for(int i = 1; i <= str1.size(); i++)
  {
    for(int j = 1; j <= str2.size(); j++)
    {
      if(str1[i-1] == str2[j-1])
        dp[i][j] = dp[i-1][j-1] + 1;
      else
        dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
      if(len < dp[i][j])
      {
        len = dp[i][j];
        pos = std::make_pair(i, j);
      }
    }
  }
  std::cout << len;
  const int dy[] = {0, -1};
  const int dx[] = {-1, 0};
  std::stack<char> st;
  while(len)
  {
    int nd = -1;
    for(int dir = 0; dir < 2; dir++)
    {
      int ny = pos.first + dy[dir];
      int nx = pos.second + dx[dir];
      if(dp[ny][nx] == len)
      {
        nd = dir;
        break;
      }
    }
    if(nd != -1)
    {
      pos.first = pos.first + dy[nd];
      pos.second = pos.second + dx[nd];
    }
    else
    {
      st.push(str1[pos.first-1]);
      pos.first -= 1;
      pos.second -= 1;
      len--;
    }
  }
  while(st.size())
    std::cout << st.top(), st.pop();
  return 0;
}