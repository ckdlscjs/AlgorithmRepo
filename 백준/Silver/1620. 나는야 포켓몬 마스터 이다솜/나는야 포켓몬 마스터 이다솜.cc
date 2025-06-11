/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, M;
std::string poke[100'005];
std::unordered_map<std::string, int> nums;
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for(int n = 1; n <= N; n++)
    {
        std::string name;
        std::cin >> name;
        poke[n] = name;
        nums[name] = n;
    }
    for(int m = 0; m < M; m++)
    {
        std::string input;
        std::cin >> input;
        if(std::isdigit(input[0])) std::cout << poke[std::stoi(input)] << '\n';
        else std::cout << nums[input] << '\n';
    }
    return 0;
}
