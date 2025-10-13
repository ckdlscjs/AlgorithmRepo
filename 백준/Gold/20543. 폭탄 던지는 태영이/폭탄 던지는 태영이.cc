/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
long long N, M, arr[2002][2002], result[2002][2002];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cin >> arr[i][j];
            //arr[i][j] *= -1;
        }
    }
        
    for(int i = M/2; i < N - M/2; i++)
    {
        for(int j = M/2; j < N - M/2; j++)
        {
            result[i][j] = arr[i-M/2][j-M/2];
            if(i - M/2 -1 >= 0) result[i][j] -= arr[i-M/2-1][j-M/2];
            if(j - M/2 -1 >= 0) result[i][j] -= arr[i-M/2][j-M/2-1];
            if(i - M/2 -1 >= 0 && j - M/2 -1 >= 0)result[i][j] += arr[i-M/2-1][j-M/2-1];
            if(i-M >= 0) result[i][j] += result[i-M][j];
            if(j-M >= 0) result[i][j] += result[i][j-M];
            if(i-M >= 0 && j-M >= 0) result[i][j] -= result[i-M][j-M];
        }
    }
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cout << result[i][j]*-1 << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
