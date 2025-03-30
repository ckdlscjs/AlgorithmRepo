#include <bits/stdc++.h>
using namespace std;
int T, N;
bool CheckNotation(int val, int num)
{
    std::vector<int> vec;
    while(val)
    {
        vec.push_back(val % num);
        val /= num;
    }
    for(int i = 0; i < vec.size() / 2; i++)
        if(vec[i] != vec[vec.size()- 1 - i]) return false;
    return true;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> T;
    for(int t = 0; t < T; t++)
    {
        std::cin >> N;
        bool chk = false;
        for(int i = 2; i <= 64 && i <= N; i++)
        {
            chk |= CheckNotation(N, i);
            if(chk) break;
        }
        std::cout << (chk ? 1 : 0) << '\n';
    }
    return 0;
}
