/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, res;
std::pair<int, int> inputs[100'005];
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++) std::cin >> inputs[n].first >> inputs[n].second;
    std::sort(inputs, inputs+N, [](const std::pair<int, int>& a, const std::pair<int, int>& b)->bool{
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    });
    std::pair<int, int> cur = inputs[0];
    res++;
    for(int n = 1; n < N; n++)
    {
        if(inputs[n].first < cur.second) continue;
        cur = inputs[n];
        res++;
    }
    std::cout << res;
    return 0;
}
