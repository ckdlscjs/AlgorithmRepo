#include <bits/stdc++.h>
using namespace std;
const int MaxN = 10005;
int arr[MaxN];
int solution(int n) 
{
    int answer = 0;
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += i;
        arr[i] = sum;
    }
    for(int i = n; i >= 1; i--)
    {
       for(int j = i-1; arr[i] - arr[j] <= n && j >= 0; j--)
       {
           if(arr[i] - arr[j] == n)
           {
               //std::cout << i << " : " << j << "->" << arr[i] - arr[j] <<'\n';
               answer++;
           }
               
       }
    }
    
    return answer;
}