#include <bits/stdc++.h>
using namespace std;

bool diagonal_ru[30];
bool diagonal_rd[30];
bool vertical[15];
int Check(const int n, int i)
{
    if(i >= n) return 1;
    int ret = 0;
    for(int j = 0; j < n; j++)
    {
        if(!vertical[j] & !diagonal_ru[i+j] & !diagonal_rd[i-j+n-1])
        {
            vertical[j] = diagonal_ru[i+j] = diagonal_rd[i-j+n-1] = true;
            ret += Check(n, i+1);
            vertical[j] = diagonal_ru[i+j] = diagonal_rd[i-j+n-1] = false;
        }
    }
    return ret;
}
int solution(int n) 
{
    return Check(n, 0);
}