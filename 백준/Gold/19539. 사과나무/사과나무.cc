#include <bits/stdc++.h>
using namespace std;
int N, h, sum_all, sum_2;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++)
    {
        std::cin >> h;
        sum_all += h;
        sum_2 += h / 2;
    }
    if(sum_all % 3 == 0 && sum_2 >= sum_all / 3)
        std::cout << "YES";
    else
        std::cout << "NO";
    return 0;
}
