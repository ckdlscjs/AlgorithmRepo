#include <bits/stdc++.h>
using namespace std;

long long solution(int r1, int r2) 
{
    long long int answer = 0;
    for(long long int x = 1; x <= r2; x++)
    {
        long long int maxy = std::floor(std::sqrt(r2*1LL*r2 - x*1LL*x));
        long long int miny = std::ceil(std::sqrt(r1*1LL*r1 - x*1LL*x));
        answer += maxy - miny + 1;
    }
    return answer * 4;
}