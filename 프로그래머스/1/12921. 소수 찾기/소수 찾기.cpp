//https://school.programmers.co.kr/learn/courses/30/lessons/12921
#include <bits/stdc++.h>

using namespace std;
bool NotPrime[1'000'005];
int solution(int n) 
{
    int answer = 0;
    for(int i = 2; i <= n; i++)
    {
        if(NotPrime[i])
            continue;
        answer++;
        for(int j = 2; i * j <= n; j++)
            NotPrime[i*j] = true;
    }
    return answer;
}