#include <bits/stdc++.h>
using namespace std;
int N, cnt, x, y;
std::unordered_map<int, int> Xcnt;
std::unordered_map<int, int> Ycnt;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++)
    {
        std::cin >> x >> y;
        Xcnt[x]++;
        Ycnt[y]++;
    }
    for(const auto& iter : Xcnt)
        cnt += iter.second >= 2 ? 1 : 0;
    for(const auto& iter : Ycnt)
        cnt += iter.second >= 2 ? 1 : 0;
    std::cout << cnt;
    return 0;
}
