#include <bits/stdc++.h>
using namespace std;
int M, N, res[5];
std::string str[505];
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::unordered_map<std::string, int> idxs;
    idxs["................"] = 0;
    idxs["****............"] = 1;
    idxs["********........"] = 2;
    idxs["************...."] = 3;
    idxs["****************"] = 4;
    std::cin >> M >> N;
    for(int m = 0; m < 5*M + 1; m++)
        std::cin >> str[m];
    for(int m = 0; m < M; m++)
    {
        for(int n = 0; n < N; n++)
        {
            int offsetm = m*5+1;
            int offsetn = n*5+1;
            std::string temp;
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 4; j++)
                {
                    temp += str[i+offsetm][j+offsetn];
                }
            }
            res[idxs[temp]]++;
        }
    }
    for(int i = 0; i < 5; i++)
        std::cout << res[i] << ' ';
    return 0;
}
