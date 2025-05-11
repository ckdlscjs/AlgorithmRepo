#include <bits/stdc++.h>
using namespace std;
using pll = std::pair<long long, long long>;
pll pos[4];
long long ccw(pll lpos1, pll lpos2, pll spos) 
{
    pll vec1 = std::make_pair(lpos1.first - spos.first, lpos1.second - spos.second);
    pll vec2 = std::make_pair(lpos2.first - spos.first, lpos2.second - spos.second);
    long long cross = vec1.first*vec2.second - vec1.second*vec2.first;
    return cross == 0 ? 0 : cross < 0 ? -1 : 1;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < 4; i++) std::cin >> pos[i].first >> pos[i].second;

    int ret1 = ccw(pos[0], pos[1], pos[2]) * ccw(pos[0], pos[1], pos[3]);
    int ret2 = ccw(pos[2], pos[3], pos[0]) * ccw(pos[2], pos[3], pos[1]);
    if(ret1 <= 0 && ret2 <= 0)
    {
        if(ret1 == 0 && ret2 == 0)
        {
            if(pos[1] < pos[0]) std::swap(pos[0], pos[1]);
            if(pos[3] < pos[2]) std::swap(pos[2], pos[3]);
            if(pos[0] <= pos[3] && pos[2] <= pos[1]) std::cout << 1;
            else std::cout << 0;
        }
        else std::cout << 1;
    }
    else std::cout << 0;

    return 0;
}
