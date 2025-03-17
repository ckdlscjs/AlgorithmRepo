/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
int N;
std::pair<int, int> inputs[52];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> inputs[i].first >> inputs[i].second;
    for(int i = 0; i < N; i++)
    {
        int cnt = 0;
        for(int j = 0; j < N; j++)
        {
            if(i == j) continue;
            if(inputs[i].first >= inputs[j].first || inputs[i].second >= inputs[j].second) cnt++;
        }
        std::cout << N-cnt << ' ';  
    }
    
    return 0;
}