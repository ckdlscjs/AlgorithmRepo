#include <bits/stdc++.h>
/*
n 명 
2~ 30명
1 2 3 4 5 6 7 
x o x x x o x
*/
using namespace std;
const int MaxN = 32;
int check[MaxN];
int solution(int n, vector<int> lost, vector<int> reserve) 
{
    for(int i = 1; i <= n; i++)
        check[i]++;
    for(const int& idx : reserve)
        check[idx]++;
    for(const int& idx : lost)
        check[idx]--;
    
    for(int idx = 1; idx <= n; idx++)
    {
        if(check[idx])
            continue;
        if(idx-1 >= 1 && check[idx-1] > 1)
        {
            check[idx] = 1;
            check[idx-1] = 1;
        }
        else if(idx+1 <= n && check[idx+1] > 1)
        {
            check[idx] = 1;
            check[idx+1] = 1;
        }
    }
    int answer = 0;
    for(int i = 1; i <= n; i++)
    {
        if(check[i] >= 1)
        {
            std::cout << i << ' ';
            answer++;
        }
    }
    return answer;
}