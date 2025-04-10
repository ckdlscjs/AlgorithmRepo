#include <bits/stdc++.h>
using namespace std;
int N, lis[1'005], len, val;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    for(int i = 0; i < N; i++)
    {
        std::cin >> val;
        if(len == 0 || lis[len-1] < val)
        {
            lis[len++] = val;
        }
        else
        {
            int lo = -1, hi = len;
            while(lo + 1 < hi)
            {
                int mid = (lo + hi) / 2;
                if(val <= lis[mid]) hi = mid;
                else lo = mid;
            }
            lis[hi] = val;
        }
    }
    std::cout << len;
    return 0;
}
