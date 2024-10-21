//https://school.programmers.co.kr/learn/courses/30/lessons/12931
#include <bits/stdc++.h>
using namespace std;
int solution(int n)
{
    int sum = 0;
    while(n)
    {
        sum += n%10;
        n /= 10;
    }
    return sum;
}