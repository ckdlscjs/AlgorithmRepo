//https://school.programmers.co.kr/learn/courses/30/lessons/12947
#include <bits/stdc++.h>
using namespace std;
bool solution(int x) 
{
    int num = x;
    int sum = 0;
    while(num)
    {
        sum += num%10;
        num/= 10;
    }
    return x % sum == 0 ? true : false;
}