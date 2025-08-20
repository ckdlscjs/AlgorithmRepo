/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, K, arr[2][100'005];
bool visited[2][100'005];
std::queue<std::tuple<int, int, int>> q;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> N >> K;
    for(int i = 0; i < 2; i++)
    {
        std::string str;
        std::cin >> str;
        for(int j = 0; j < N; j++)
        {
            arr[i][j] = str[j] - '0';
            //std::cout << arr[i][j];
        }
        //std::cout << '\n';
    }
    visited[0][0] = true;
    q.push({0, 0, 0});
    while(q.size())
    {
        auto cur = q.front();
        q.pop();
        int ct = std::get<0>(cur);
        int cy = std::get<1>(cur);
        int cx = std::get<2>(cur);
        if(cx+1 >= N)
        {
            std::cout << 1;
            return 0;
        }
        if(arr[cy][cx + 1] == 1 && !visited[cy][cx+1])
        {
            visited[cy][cx+1] = true;
            q.push({ct + 1, cy, cx+1});
        }
        
        if(0 <= cx -1 && ct + 1 <= cx-1 && arr[cy][cx-1] == 1 && !visited[cy][cx-1])
        {
            visited[cy][cx-1] = true;
            q.push({ct + 1, cy, cx-1});
        }
        int ny = cy ? 0 : 1;
        if(cx + K >= N)
        {
            std::cout << 1;
            return 0;
        }
        if(arr[ny][cx+K] == 1 && !visited[ny][cx+K])
        {
            
            visited[ny][cx+K] = true;
            q.push({ct + 1, ny, cx+K});
        }
    }
    std::cout << 0;
	return 0;
}

