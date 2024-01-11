#include <bits/stdc++.h>

using namespace std;
int solution(vector<vector<int>> dots) 
{
    for(int i = 3; i < 16; i++)
    {
        std::vector<std::pair<int, int>> a;
        std::vector<std::pair<int, int>> b;
        for(int j = 0; j < 4; j++)
        {
            if((i & (1 << j)) == (1 << j))
                a.push_back(std::make_pair(dots[j][0], dots[j][1]));
            else
                b.push_back(std::make_pair(dots[j][0], dots[j][1]));   
        }
        if(a.size() != b.size())
            continue;
        for(auto iter : a)
            std::cout << iter.first << ',' << iter.second << ' ';
        std::cout << ':';
        for(auto iter : b)
            std::cout << iter.first << ',' << iter.second << ' ';
        std::cout << '\n';
        float ar, br;
        ar = (a[1].second - a[0].second) / (float)(a[1].first - a[0].first);
        br = (b[1].second - b[0].second) / (float)(b[1].first - b[0].first);
        if(std::abs(ar - br) <= 0.001f)
            return 1;   
    }
    return 0;
}