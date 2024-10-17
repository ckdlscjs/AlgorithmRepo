//https://school.programmers.co.kr/learn/courses/30/lessons/12947
#include <bits/stdc++.h>
using namespace std;
int solution(int num) 
{
    long long int n = num;
    int cnt = 0;
    while(n != 1 && cnt <= 500)
    {
        if(n%2 == 0)
            n /= 2;
        else
            n = n * 3 + 1;
        cnt++;
    }
    return (n == 1 && cnt < 500) ? cnt : -1;
}