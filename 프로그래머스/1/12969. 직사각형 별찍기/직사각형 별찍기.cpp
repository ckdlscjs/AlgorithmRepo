//https://school.programmers.co.kr/learn/courses/30/lessons/12969
#include <bits/stdc++.h>
using namespace std;
int n, m;
int main(void) 
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            std::cout <<'*';
        std::cout<<'\n';
    }
    return 0;
}