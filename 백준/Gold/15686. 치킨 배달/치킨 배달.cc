#include <bits/stdc++.h>
using namespace std;
int N, M, arr[52][52], chk[15], res = 2500*2501;
std::vector<std::pair<int, int>> homes;
std::vector<std::pair<int, int>> chickens;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cin >> arr[i][j];
            if(arr[i][j] == 1)
                homes.push_back({i, j});
            else if(arr[i][j] == 2)
                chickens.push_back({i, j});
        }
    }
    
    std::function<void(int, int)> func = [&](int idx, int cur) -> void 
    {
        if(idx > chickens.size()) return;
        if(cur >= M)
        {
            int sum = 0;
            for(const auto& iter : homes)
            {
                int dist = 2501;
                for(int i = 0; i < M; i++)
                    dist = std::min(std::abs(iter.first - chickens[chk[i]].first) + std::abs(iter.second - chickens[chk[i]].second), dist);
                sum += dist;
            }
            res = std::min(res, sum);
            return;
        }
        chk[cur] = idx;
        func(idx+1, cur+1);
        func(idx+1, cur);
    };
    func(0, 0);
    std::cout << res;
    return 0;
}
