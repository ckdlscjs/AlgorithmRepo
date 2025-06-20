/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
const int MD[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int N, res;
std::pair<int, int> SEMD, flowers[100'005];
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    SEMD.first = 1; SEMD.second = 30;
    for(int i = 0; i < 3; i++) SEMD.first += MD[i];
    for(int i = 0; i < 11; i++) SEMD.second += MD[i];
    //std::cout << SEMD.first << ' ' << SEMD.second << '\n';
    
    for(int n = 0; n < N; n++)
    {
        int sm, sd, em, ed;
        std::cin >> sm >> sd >> em >> ed;
        flowers[n].first = sd;
        flowers[n].second = ed;
        for(int i = 0; i < sm; i++) flowers[n].first += MD[i];
        for(int i = 0; i < em; i++) flowers[n].second += MD[i];
        //std::cout << flowers[n].first << ' ' << flowers[n].second << '\n';
    }
    std::sort(flowers, flowers+N, [](const std::pair<int, int>& a, const std::pair<int, int>& b)->bool{
        return a.first == b.first ? a.second > b.second : a.first < b.first;
    });
    
    /*
    for(int n = 0; n < N; n++)
    {
       std::cout << flowers[n].first << ' ' << flowers[n].second << '\n';
    }
    std::cout << '\n';
    */
    if(flowers[0].first > SEMD.first)
    {
        std::cout << 0;
        return 0;
    }
    std::pair<int, int> cur(60, 60);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>> pq;
    for(int n = 0; n < N; n++)
    {
        if(flowers[n].first > cur.second) //현재 입력된 꽃의 시작날짜가 현재 꽃의 끝나는날짜보다 큰경우
        {
            if(pq.empty() || flowers[n].first > pq.top().first) //저장된 꽃이 없거나 pq에저장된 가장 끝나는날짜가 긴 꽃보다 현재 피는시기가 늦는경우
            {
                std::cout << 0;
                return 0;
            }
            cur = std::make_pair(pq.top().second, pq.top().first);
            //std::cout << n << ' ' << cur.first << ' ' << cur.second << '\n';
            while(pq.size()) pq.pop();
            res++;
        }
        pq.push({flowers[n].second, flowers[n].first});
    }
    if(cur.second <= SEMD.second)
    {
        if(pq.empty() || (pq.size() && pq.top().first <= SEMD.second))
        {
            std::cout << 0;
            return 0;
        }
        else if(pq.size() && pq.top().first > SEMD.second)
        {
            std::cout << res + 1;
            return 0;
        }
    }
    std::cout << res;
    return 0;
}
