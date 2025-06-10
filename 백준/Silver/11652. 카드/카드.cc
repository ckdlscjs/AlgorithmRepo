/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
long long N, input;
std::pair<long long, int> largest(LLONG_MAX, 0);
std::unordered_map<long long, int> cnts;
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++)
    {
        std::cin >> input;
        cnts[input]++;
        if(cnts[input] >= largest.second)
        {
            if(largest.second == cnts[input] && largest.first < input) continue;
            largest.first = input;
            largest.second = cnts[input];
        }
    }
    std::cout << largest.first;
    return 0;
}
