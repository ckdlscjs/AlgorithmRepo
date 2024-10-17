#include <bits/stdc++.h>
long long int n, atk, t, a, h, curhp, maxhp;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n >> atk;
    for(int i = 0; i < n; i++)
    {
        std::cin >> t >> a >> h;
        if(t == 1)
        {
            long long int d = a * (std::ceil((double)h / atk) - 1);
            if(curhp < d)
            {
                maxhp += d - curhp;
                curhp = 0;
            }
            else
            {
                curhp -= d;
            }
        }
        else
        {
            atk += a;
            curhp = std::min(maxhp, curhp + h);
        }
    }
    std::cout << maxhp + 1;
    return 0;
}