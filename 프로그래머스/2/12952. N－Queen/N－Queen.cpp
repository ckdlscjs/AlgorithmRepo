#include <bits/stdc++.h>
using namespace std;
int arr[15];
bool CheckQueen(int y)
{
    for(int i = 0; i < y; i++)
        if(arr[y] == arr[i] || y-i == std::abs(arr[y] - arr[i])) return false;
    return true;
}
int Check(const int& n, int y)
{
    if(y >= n) return 1;
    int ret = 0;
    for(int j = 0; j < n; j++)
    {
        arr[y] = j;
        if(CheckQueen(y))
            ret += Check(n, y+1);
    }
    return ret;
}
int solution(int n) 
{
    return Check(n, 0);
}