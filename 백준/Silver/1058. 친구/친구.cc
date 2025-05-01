#include <bits/stdc++.h>
using namespace std;
int N, res;
std::string arr[52];
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++) std::cin >> arr[n];
    for(int i = 0; i < N; i++)
    {
        int cnt = 0;
        for(int j = 0; j < arr[i].size(); j++)
        {
            if(i == j) continue;
            if(arr[i][j] == 'Y') cnt++;
            else
            {
                for(int k = 0; k < N; k++)
                {
                    if(arr[i][k] == 'Y' && arr[j][k] == 'Y')
                    {
                        cnt++;
                        break;
                    }
                }
            }
        }
        res = std::max(res, cnt);
    }
    std::cout << res;
    return 0;
}
