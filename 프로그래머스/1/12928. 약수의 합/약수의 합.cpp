//https://school.programmers.co.kr/learn/courses/30/lessons/12928
#include <bits/stdc++.h>
using namespace std;

int solution(int n) 
{
    int sum = 0;
    std::unordered_set<int> divisors;
    for(int i = 1; i <= std::sqrt(n); i++)
    {
        if(n%i == 0)
        {
            divisors.insert(i);
            divisors.insert(n/i);
        }
    }
    for(const auto& iter : divisors)
        sum += iter;
    return sum;
}