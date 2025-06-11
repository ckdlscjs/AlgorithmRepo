/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, M;
std::unordered_map<std::string, std::string> sp;
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for(int n = 0; n < N; n++)
    {
        std::string site, pass;
        std::cin >> site >> pass;
        sp[site] = pass;
    }
    for(int m = 0; m < M; m++)
    {
        std::string site;
        std::cin >> site;
        std::cout << sp[site] << '\n';
    }
    return 0;
}
