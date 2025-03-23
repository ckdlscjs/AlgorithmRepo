#include <bits/stdc++.h>
int N, M;
std::string key, value;
std::unordered_map<std::string, std::string> chks;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for(int n = 0; n < N; n++)
    {
        std::cin >> key >> value;
        chks[key] = value;
    }
    for(int m = 0; m < M; m++)
    {
        std::cin >> key;
        std::cout << chks[key] << '\n';
    }
	return 0;
}