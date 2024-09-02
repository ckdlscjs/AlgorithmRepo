#include <bits/stdc++.h>
using namespace std;
int solution(int n)
{
    int ans = 0;
    while(n)
    {
        ans = n%2 ? ans+1 : ans;
        n = n%2 ? n-1 : n/2;
    }
    return ans;
}