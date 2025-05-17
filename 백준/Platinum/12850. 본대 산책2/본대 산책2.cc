#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll Mod = 1'000'000'007;
std::vector<std::vector<ll>> adj = 
{
    {0, 1, 0, 1, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 1, 0, 0},
    {1, 1, 1, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 1, 1, 0},
    {0, 0, 1, 1, 1, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 1, 0},
};
ll D;
std::vector<std::vector<ll>> Multiply(std::vector<std::vector<ll>> mat1, std::vector<std::vector<ll>> mat2)
{
    std::vector<std::vector<ll>> ret(mat1.size(), std::vector<ll>(mat1[0].size(), 0LL));
    for(int i = 0; i < mat1.size(); i++)
    {
        for(int j = 0; j < mat1.size(); j++)
        {
            for(int k = 0; k < mat1.size(); k++)
            {
                ret[i][j] += (mat1[i][k] * mat2[k][j]) % Mod;
                ret[i][j] %= Mod;
            }
        }
    }
    return ret;
}
std::vector<std::vector<ll>> Square(std::vector<std::vector<ll>> mat, ll K)
{
    if(K <= 1) return adj;
    std::vector<std::vector<ll>> temp = Square(mat, K/2);
    std::vector<std::vector<ll>> ret = Multiply(temp, temp);
    if(K % 2 == 1)
        ret = Multiply(ret, adj);
    return ret;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> D;
    std::cout << Square(adj, D)[0][0];
    return 0;
}
