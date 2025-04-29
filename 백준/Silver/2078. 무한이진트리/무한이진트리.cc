#include <bits/stdc++.h>
using namespace std;
int A, B, L, R;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> A >> B;
    while(A != B)
    {
        if(A > B)
        {
            int cnt = A/B;
            if(B == 1)
                cnt--;
            A -= cnt * B;
            L += cnt;
        }
        else
        {
            int cnt = B/A;
            if(A == 1)
                cnt--;
            B -= cnt * A;
            R += cnt;
        }
    }
    std::cout << L << ' ' << R;
    return 0;
}
