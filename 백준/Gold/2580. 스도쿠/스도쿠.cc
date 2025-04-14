#include <bits/stdc++.h>
using namespace std;
int arr[10][10];
std::vector<std::pair<int, int>> zeros;
bool chk = false;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            std::cin >> arr[i][j];
            if(arr[i][j] == 0)
                zeros.push_back({i, j});
        }
    }
    std::function<void(int)> func = [&](int idx) -> void
    {
        if(chk) return;
        if(idx >= zeros.size())
        {
            chk = true;
            for(int i = 0; i < 9; i++)
            {
                for(int j = 0; j < 9; j++)
                {
                    std::cout << arr[i][j] << ' ';
                }
                std::cout << '\n';
            }
            return;
        }
        int i = zeros[idx].first;
        int j = zeros[idx].second;
        for(int num = 1; num <= 9; num++)
        {
            arr[i][j] = num;
            auto check = [](int y, int x)->bool
            {
                //vertical
                int mask = 0;
                for(int i = 0; i < 9; i++)
                {
                    if(arr[i][x] == 0) continue;
                    if(mask & (1 << (arr[i][x]-1))) return false;
                    mask |= (1 << (arr[i][x]-1));
                }
                //horizon
                mask = 0;
                for(int j = 0; j < 9; j++)
                {
                    if(arr[y][j] == 0) continue;
                    if(mask & (1 << (arr[y][j]-1))) return false;
                    mask |= (1 << (arr[y][j]-1));
                }
                //cube
                mask = 0;
                y = y / 3 * 3;
                x = x / 3 * 3;
                for(int i = 0; i < 3; i++)
                {
                    for(int j = 0; j < 3; j++)
                    {
                        if(arr[y+i][x+j] == 0) continue;
                        if(mask & (1 << (arr[y+i][x+j]-1))) return false;
                        mask |= (1 << (arr[y+i][x+j]-1));
                    }
                }
                return true;
            };
            if(check(i, j)) func(idx+1);
            arr[i][j] = 0;
            if(chk) return;
        }
    };
    func(0);
    return 0;
}
