#include <bits/stdc++.h>
int T, M, N, x, y;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    for(int t = 0; t < T; t++)
    {
        std::cin >> M >> N >> x >> y;
        int A = std::max(M, N);
        int B = std::min(M, N);
        while(A % B)
        {
            int temp = A % B;
            A = B;
            B = temp;
        }
        int LCM = M * N / B;
        int cur = -1;
        for(int nx = x; nx <= LCM; nx += M)
        {
            int ny = nx % N;
            if(ny == 0) ny = N;
            if(ny == y)
            {
                cur = nx;
                break;
            }
        }
        
        std::cout << cur << '\n';
    }
	return 0;
}