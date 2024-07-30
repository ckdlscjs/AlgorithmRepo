#include <bits/stdc++.h>
using namespace std;

int solution(int n, int a, int b)
{
    a += n - 1;
    b += n - 1;
    int cnt = 0;
    while(a != b)
    {
        cnt++;
        a /= 2;
        b /= 2;
    }
    return cnt;
}