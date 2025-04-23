#include <bits/stdc++.h>
using namespace std;
long long P[3][2], result;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < 3; i++) std::cin >> P[i][0] >> P[i][1];
    result = (P[1][0] - P[0][0])*(P[2][1] - P[0][1]) - (P[1][1] - P[0][1])*(P[2][0] - P[0][0]);
    result = result == 0 ? 0 : result > 0 ? 1 : -1;
    std::cout << result;
    
    return 0;
}