#include <bits/stdc++.h>
using namespace std;
std::string s;
int N, M, K, p, smin, smax;
std::unordered_map<std::string, int> chks;
std::set<std::pair<int, std::string>> inputs;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N >> M >> K;
    for(int n = 0; n < N; n++)
    {
        std::cin >> s >> p;
        inputs.insert({p, s});
        chks[s] = p;
    }

    for(int k = 0; k < K; k++)
    {
        std::cin >> s;
        smin += chks[s];
        smax += chks[s];
        inputs.erase({chks[s], s});
        chks.erase(s);
    }
    auto miniter = inputs.begin();
    auto maxiter = inputs.rbegin();
    for(int m = K; m < M; m++)
    {
        smin += miniter->first;
        smax += maxiter->first;
        miniter++;
        maxiter++;
    }
    std::cout << smin << ' ' << smax;
    return 0;
}
