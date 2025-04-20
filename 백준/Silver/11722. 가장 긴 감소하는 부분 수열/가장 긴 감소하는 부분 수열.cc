#include <bits/stdc++.h>
using namespace std;
int N, val, lis[1'005], len;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++)
    {
        std::cin >> val;
        if(len == 0 || lis[len-1] > val)
        {
            lis[len++] = val;
        }
        else
        {
            int lo = -1, hi = len;
            while(lo + 1 < hi)
            {
                int mid = (lo + hi) / 2;
                if(lis[mid] <= val) hi = mid;
                else lo = mid;
            }
            lis[hi] = val;
        }
    }
    std::cout << len;
    return 0;
}