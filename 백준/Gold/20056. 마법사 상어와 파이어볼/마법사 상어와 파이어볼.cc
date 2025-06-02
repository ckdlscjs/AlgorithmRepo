/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
using pii = std::pair<int, int>;
using ti5 = std::tuple<int, int, int, int, int>;
using ti3 = std::tuple<int, int, int>;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int N, M, K, r, c, m, s, d, res;
std::queue<ti5> q;
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> K;
    for(int i = 0; i < M; i++)
    {
        std::cin >> r >> c >> m >> s >> d;
        q.push({r-1, c-1, m, s, d});
    }
    for(int k = 0; k < K; k++)
    {
        res = 0;
        std::map<pii, std::vector<ti3>> boards;
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            r = std::get<0>(cur);
            c = std::get<1>(cur);
            m = std::get<2>(cur);
            s = std::get<3>(cur);
            d = std::get<4>(cur);
            int ny = r + dy[d] * (s%N);
            if(ny < 0) ny += N;
            ny %= N;
            int nx = c + dx[d] * (s%N);
            if(nx < 0) nx += N;
            nx %= N;
            boards[{ny, nx}].push_back({m, s, d});
        }
        for(const auto& iter : boards)
        {
            if(iter.second.size() <= 1)
            {
                q.push({iter.first.first, iter.first.second, std::get<0>(iter.second[0]), std::get<1>(iter.second[0]), std::get<2>(iter.second[0])});
                res += std::get<0>(iter.second[0]);
            }
            else
            {
                int sum_m = 0, sum_s = 0, cnt_odd = 0, cnt_even = 0;
                for(const auto& fb : iter.second)
                {
                    sum_m += std::get<0>(fb);
                    sum_s += std::get<1>(fb);
                    cnt_odd += std::get<2>(fb) % 2 ? 1 : 0;
                    cnt_even += std::get<2>(fb) % 2 ? 0 : 1;
                }
                sum_m = std::floor(sum_m/5);
                sum_s = std::floor(sum_s/iter.second.size());
                if(sum_m <= 0) continue;
                if(cnt_odd >= iter.second.size() || cnt_even >= iter.second.size())
                {
                    q.push({iter.first.first, iter.first.second, sum_m, sum_s, 0});
                    q.push({iter.first.first, iter.first.second, sum_m, sum_s, 2});
                    q.push({iter.first.first, iter.first.second, sum_m, sum_s, 4});
                    q.push({iter.first.first, iter.first.second, sum_m, sum_s, 6});
                }
                else
                {
                    q.push({iter.first.first, iter.first.second, sum_m, sum_s, 1});
                    q.push({iter.first.first, iter.first.second, sum_m, sum_s, 3});
                    q.push({iter.first.first, iter.first.second, sum_m, sum_s, 5});
                    q.push({iter.first.first, iter.first.second, sum_m, sum_s, 7});
                }
                res += sum_m*4;
            }
        }
    }
    std::cout << res;
    return 0;
}
