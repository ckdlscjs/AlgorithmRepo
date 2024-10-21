//https://school.programmers.co.kr/learn/courses/30/lessons/12934
#include <bits/stdc++.h>
using namespace std;
long long solution(long long n) 
{
    return n == std::pow((long long int)std::sqrt(n), 2) ? std::pow((long long int)std::sqrt(n) + 1, 2) : -1;
}