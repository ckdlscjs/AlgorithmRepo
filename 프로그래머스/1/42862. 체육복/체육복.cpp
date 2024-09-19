#include <bits/stdc++.h>

using namespace std;

int sportswear[32];
int solution(int n, vector<int> lost, vector<int> reserve) 
{
    for(const auto& iter : lost)
        sportswear[iter]--;
    for(const auto& iter : reserve)
        sportswear[iter]++;
    int answer = 0;
    for(int i = 1; i <= n; i++)
    {
        if(sportswear[i] >= 1 && sportswear[i-1] < 0)
        {
            sportswear[i-1] += 1;
            sportswear[i] -= 1;
        }
        if(sportswear[i] >= 1 && sportswear[i+1] < 0)
        {
            sportswear[i+1] += 1;
            sportswear[i] -= 1;
        }
    }
    for(int i = 1; i <= n; i++)
        if(sportswear[i] >= 0)
            answer++;
    return answer;
}