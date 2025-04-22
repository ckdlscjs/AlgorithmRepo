#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int costs[5][5], order, dp[100'002][5][5];
std::vector<int> arr;
int Check(int idx, int lf, int rf)
{
    if(idx >= arr.size()) return 0;
    int& ref = dp[idx][lf][rf];
    if(ref != -1) return ref;
    ref = INF;
    ref = std::min(ref, Check(idx+1, arr[idx], rf) + costs[lf][arr[idx]]);
    ref = std::min(ref, Check(idx+1, lf, arr[idx]) + costs[rf][arr[idx]]);
    return ref;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    costs[0][1] = 2; costs[0][2] = 2; costs[0][3] = 2; costs[0][4] = 2;
    costs[1][1] = 1; costs[1][2] = 3; costs[1][3] = 4; costs[1][4] = 3;
    costs[2][1] = 3; costs[2][2] = 1; costs[2][3] = 3; costs[2][4] = 4;
    costs[3][1] = 4; costs[3][2] = 3; costs[3][3] = 1; costs[3][4] = 3;
    costs[4][1] = 3; costs[4][2] = 4; costs[4][3] = 3; costs[4][4] = 1;

    std::memset(dp, -1, sizeof(dp));
    
    while(std::cin >> order)
    {
        if(order == 0) break;
        arr.push_back(order);
    }
    std::cout << Check(0, 0, 0);
    return 0;
}