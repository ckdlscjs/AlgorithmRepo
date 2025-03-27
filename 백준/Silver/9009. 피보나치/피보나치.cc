#include <bits/stdc++.h>
int T, N;
std::vector<int> fibos;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    fibos.push_back(1);
    fibos.push_back(1);
    while(fibos[fibos.size()-1] + fibos[fibos.size()-2] <= 1'000'000'000)
        fibos.push_back(fibos[fibos.size()-1] + fibos[fibos.size()-2]);
    std::cin >> T;
    for(int t = 0; t < T; t++)
    {
        std::cin >> N;
        std::stack<int> results;
        for(int i = fibos.size()-1; i >= 0; i--)
        {
            if(fibos[i] > N) continue;
            results.push(fibos[i]);
            N -= fibos[i];
        }
        while(results.size())
        {
            std::cout << results.top() << ' ';
            results.pop();
        }
        std::cout << '\n';
    }
    return 0;
}