#include <bits/stdc++.h>
using namespace std;
std::string str1, str2;
const int dy[] = {0, -1};
const int dx[] = {-1, 0};
int dp[1005][1005], res;
std::pair<int, int> respos;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> str1 >> str2;
  for(int i = 1; i <= str2.size(); i++)
  {
    for(int j = 1; j <= str1.size(); j++)
    {
      if(str1[j-1] == str2[i-1])
      {
        dp[i][j] = dp[i-1][j-1] + 1;
      }
      else
      {
        dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
      }
      if(res < dp[i][j])
      {
        res = dp[i][j];
        respos.first = i;
        respos.second = j;
      }
    }
  }
  std::cout << res << '\n';
  if(res)
  {
    std::stack<char> st;
    while(dp[respos.first][respos.second] != 0)
    {
      int next = -1;
      for(int dir = 0; dir < 2; dir++)
      {
        int ny = respos.first + dy[dir];
        int nx = respos.second + dx[dir];
        if(dp[ny][nx] == dp[respos.first][respos.second])
          next = dir;
      }
      if(next == -1)
      {
        st.push(str2[respos.first-1]);
        respos.first -= 1;
        respos.second -= 1;
      }
      else
      {
        respos.first = respos.first + dy[next];
        respos.second = respos.second + dx[next];
      }
    }
    while(st.size())
    std::cout << st.top(), st.pop();
  }
  
  return 0;
}