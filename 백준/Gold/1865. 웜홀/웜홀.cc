#include <bits/stdc++.h>
using namespace std;
using tiii = std::tuple<int, int, int>;
const int INF = 10'000*500 + 5;
int TC, N, M, W, S, E, T;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> TC;
    for(int tc = 0; tc < TC; tc++)
    {
        std::cin >> N >> M >> W;
        std::vector<int> costs(N+1, INF);
        std::vector<tiii> edges;
        //도로는 양방향, 웜홀은 단방향이다
        for(int m = 0; m < M; m++)
        {
            std::cin >> S >> E >> T;
            edges.push_back({S, E, T});
            edges.push_back({E, S, T});
        }
        for(int w = 0; w < W; w++)
        {
            std::cin >> S >> E >> T;
            edges.push_back({S, E, -T});
        }
        bool chk = false;
        for(int i = 0; i < N; i++)
        {
            for(const auto& iter : edges)
            {
                int u = std::get<0>(iter);
                int v = std::get<1>(iter);
                int w = std::get<2>(iter);
                if(costs[u] + w < costs[v]) //음수간선은 알아서 줄기때문에 relaxation에서 costs[임의정점] = 0 의초기화가 필요없다
                {
                    if(i == N-1)
                    {
                        chk = true;
                        break;
                    }
                    costs[v] = costs[u] + w;
                }
            }
            if(chk) break;
        }
        std::cout << (chk ? "YES" : "NO") << '\n';
    }
    return 0;
}
