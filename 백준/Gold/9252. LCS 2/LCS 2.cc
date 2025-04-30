#include <bits/stdc++.h>
using namespace std;
std::string str1, str2;
const int dy[] = {-1, 0};
const int dx[] = {0, -1};
int dp[1'005][1'005];
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> str1 >> str2;
    for(int i = 1; i <= str1.size(); i++)
    {
        for(int j = 1; j <= str2.size(); j++)
        {
            if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
        }
    }
    std::string result;
    result.resize(dp[str1.size()][str2.size()]);
    int y = str1.size(), x = str2.size();
    while(dp[y][x])
    {
        int nd = -1;
        for(int dir = 0; dir < 2; dir++)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(dp[ny][nx] == dp[y][x])
            {
                nd = dir;
                break;
            }
        }
        if(nd != -1)
        {
            y += dy[nd];
            x += dx[nd];
        }
        else
        {
            result[dp[y][x]-1] = str1[y-1];
            y -= 1;
            x -= 1;
        }
    }
    std::cout << dp[str1.size()][str2.size()] << '\n' << result;
    return 0;
}
