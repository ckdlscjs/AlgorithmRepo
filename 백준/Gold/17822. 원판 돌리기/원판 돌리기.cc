/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
const int dy[] = {1, 0, 0};
const int dx[] = {0, -1, 1};
int N, M, T, arr[52][52], res;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> N >> M >> T;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            std::cin >> arr[i][j];
    for(int t = 0; t < T; t++)
    {
        int x, d, k;
        std::cin >> x >> d >> k;
        d = d == 0? 1 : -1;
        k %= M;
        for(int i = x-1; i < N; i += x)
        {
            int temp[52];
            for(int j = 0; j < M; j++)
            {
                int nj = j + d*k;
                if(nj < 0) 
                    nj += M;
                nj %= M;
                temp[nj] = arr[i][j];
            }
            std::memcpy(arr[i], temp, sizeof(temp));
        }
        /*
        for(int i = 0; i < N; i++)
        {
           for(int j = 0; j < M; j++)
           {
               std::cout << arr[i][j] << ' ';
           }
           std::cout << '\n';
        }
        std::cout << '\n';
        */
        std::set<std::pair<int, int>> chks;
        std::queue<std::pair<int, int>> tempq;
        int tempsum = 0, tempcnt = 0;
        for(int i = 0; i < N; i++)
        {
           for(int j = 0; j < M; j++)
           {
               if(arr[i][j] == 0) continue;
               tempq.push({i, j});
               tempsum += arr[i][j];
               tempcnt += 1;
               for(int dir = 0; dir < 3; dir++)
               {
                   int ny = i + dy[dir];
                   if(ny >= N) continue;
                   int nx = j + dx[dir];
                   if(nx < 0) nx += M;
                   nx %= M;
                   if(arr[i][j] == arr[ny][nx])
                   {
                       chks.insert({i, j});
                       chks.insert({ny, nx});
                   }
               }
           }
        }
        if(chks.size())
        {
            for(const auto& iter : chks)
                arr[iter.first][iter.second] = 0;
        }
        else
        {
            float avg = tempsum / (float)tempcnt;
            while(tempq.size())
            {
                auto cur = tempq.front();
                tempq.pop();
                arr[cur.first][cur.second] += (arr[cur.first][cur.second] == avg ? 0 : arr[cur.first][cur.second] > avg ? -1 : 1);
            }
        }
        /*
        for(int i = 0; i < N; i++)
        {
           for(int j = 0; j < M; j++)
           {
               std::cout << arr[i][j] << ' ';
           }
           std::cout << '\n';
        }
        std::cout << '\n';
        */
    }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            res += arr[i][j];
    std::cout << res;
	return 0;
}
