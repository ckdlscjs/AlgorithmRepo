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
        for(int ny = y; ny <= LCM; ny += N)
        {
            int nx = ny % M;
            if(nx == 0) nx = M;
            if(nx == x)
            {
                cur = ny;
                break;
            }
        }
        std::cout << cur << '\n';
    }
	return 0;
}