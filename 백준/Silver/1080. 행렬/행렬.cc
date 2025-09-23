/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, M, res;
std::string A[52], B[52];
//char A[52][52], B[52][52];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> N >> M;
    for(int n = 0; n < N; n++) std::cin >> A[n];
    for(int n = 0; n < N; n++) std::cin >> B[n];
    for(int n = 0; n <= N - 3; n++)
    {
        for(int m = 0; m <= M - 3; m++)
        {
            if(A[n][m] != B[n][m])
            {
                res++;
                for(int i = 0; i < 3; i++)
                {
                    for(int j = 0; j < 3; j++)
                    {
                        A[n + i][m + j] = (A[n + i][m + j] == '0' ? '1' : '0');
                    }
                }
            }
        }
    }
    bool chk = false;
    for(int n = 0; n < N; n++)
        if(A[n] != B[n]) chk |= true;
        
    std::cout << (chk ? -1 : res);
    return 0;
}
