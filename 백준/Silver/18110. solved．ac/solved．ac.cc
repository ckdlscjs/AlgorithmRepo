/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
int N, arr[3*100005];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> N;
    if(N == 0)
    {
        std::cout << 0;
        return 0;
    }
    for(int i = 0; i < N; i++) std::cin >> arr[i];
    std::sort(arr, arr+N);
    int exclusive = N*0.15f + 0.5f;
    int sum = 0;
    for(int i = exclusive; i < N - exclusive; i++)
    {
        sum += arr[i];
    }
    sum = (double)sum / (N - (exclusive*2)) + 0.5f;
    std::cout << sum;
    return 0;
}