/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <bits/stdc++.h>
long long int N, sum;
std::string str;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    std::cin >> str;
    for(int i = 0; i < N; i++)
    {
        long long int cur = str[i] - 'a' + 1;
        for(int j = 0; j < i; j++)
        {
            cur *= 31;
            cur %= 1234567891;
        }
        sum += cur;
        sum %= 1234567891;
    }
    std::cout << sum;
    return 0;
}