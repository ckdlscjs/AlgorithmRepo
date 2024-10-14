#include <bits/stdc++.h>
using namespace std;
int arr[35];
int solution(int n, vector<int> lost, vector<int> reserve) 
{
    for(const auto& iter : reserve)
        arr[iter]++;
    for(const auto& iter : lost)
        arr[iter]--;
    for(int i = 1; i <= n; i++)
    {
        if(arr[i] < 0 && arr[i-1] >= 1)
            arr[i] += 1, arr[i-1] -= 1;
        if(arr[i] < 0 && arr[i+1] >= 1)
            arr[i] += 1, arr[i+1] -= 1;
    }
    int answer = 0;
    for(int i = 1; i <= n; i++)
    {
       if(arr[i]>=0)
           answer++;
    }
    return answer;
}