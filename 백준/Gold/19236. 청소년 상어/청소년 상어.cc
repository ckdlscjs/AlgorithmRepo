#include <bits/stdc++.h>
using namespace std;
//↑, ↖, ←, ↙, ↓, ↘, →, ↗
using tiii = std::tuple<int, int, int>;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int arr[4][4], a, b;
int Check(int y, int x, int arr[][4], std::map<int, tiii> fishes)
{
    if(y < 0 || x < 0 || y >= 4 || x >= 4 || arr[y][x] == 0) return 0;
    int narr[4][4];
    std::memcpy(narr, arr, sizeof(narr));
    int ret = 0;
    int cur = narr[y][x];
    int dir = std::get<0>(fishes[cur]);
    fishes.erase(cur);
    narr[y][x] = 0;
    for(const auto& iter : fishes)
    {
        int ca = iter.first;
        int cd = std::get<0>(iter.second);
        int cy = std::get<1>(iter.second);
        int cx = std::get<2>(iter.second);
        int ny = cy + dy[cd];
        int nx = cx + dx[cd];
        while(ny < 0 || nx < 0 || ny >= 4 || nx >= 4 || (ny == y && nx == x))
        {
            cd++;
            cd %= 8;
            ny = cy + dy[cd];
            nx = cx + dx[cd];
        }
        if(narr[ny][nx] == 0)
        {
            std::get<0>(fishes[ca]) = cd;
            std::get<1>(fishes[ca]) = ny;
            std::get<2>(fishes[ca]) = nx;
            narr[ny][nx] = ca;
            narr[cy][cx] = 0;
        }
        else
        {
            std::get<1>(fishes[narr[ny][nx]]) = cy;
            std::get<2>(fishes[narr[ny][nx]]) = cx;
            narr[cy][cx] = narr[ny][nx];
            
            std::get<0>(fishes[ca]) = cd;
            std::get<1>(fishes[ca]) = ny;
            std::get<2>(fishes[ca]) = nx;
            narr[ny][nx] = ca;
        }
    }
    /*
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            std::cout << narr[i][j];
            if(narr[i][j] == 0) std::cout << b;
            else std::cout << std::get<0>(fishes[narr[i][j]]);
            std::cout << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    */
    
    for(int i = 1; i <= 3; i++)
    {
        int ny = y + dy[dir]*i;
        int nx = x + dx[dir]*i;
        //std::cout << ny << nx << '\n';
        ret = std::max(ret, Check(ny, nx, narr, fishes) + cur);
    }
    return ret;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::map<int, tiii> fishes;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            std::cin >> a >> b;
            arr[i][j] = a;
            fishes[a] = std::make_tuple(b-1, i, j);
        }
    }
    std::cout << Check(0, 0, arr, fishes);
    return 0;
}
