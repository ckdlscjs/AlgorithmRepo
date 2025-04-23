#include <bits/stdc++.h>
using namespace std;
long long N, X[10'005], Y[10'005];
double result;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> X[i] >> Y[i];
    X[N] = X[0]; Y[N] = Y[0];
    for(int i = 0; i < N; i++)
    {
        result += ((X[i]*Y[i+1]) - (Y[i] * X[i+1]));
    }

    std::cout << std::fixed << std::setprecision(1) << std::abs(result) * 0.5f;
    
    return 0;
}