#include <bits/stdc++.h>

using namespace std;
int dp[100005];
int Fibo(int n)
{
    if(n <= 1)
        return n == 1 ? 1 : 0;
    if(dp[n])
        return dp[n];
    dp[n] = (Fibo(n-1) + Fibo(n-2))%1234567;
    return dp[n];
}
int solution(int n) 
{
    return Fibo(n);
}