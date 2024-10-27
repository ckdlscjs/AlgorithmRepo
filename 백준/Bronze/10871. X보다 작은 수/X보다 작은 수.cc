#include <bits/stdc++.h>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int N, X;
    std::cin >> N >> X;
    for(int i = 0; i < N; i++)
    {
        int a;
        std::cin >> a;
        if(a < X) 
            std::cout << a << ' ';
    }
        
    return 0;
}