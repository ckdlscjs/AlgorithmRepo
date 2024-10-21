//https://school.programmers.co.kr/learn/courses/30/lessons/12940
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, int m) 
{
    int large = std::max(n, m);
    int small = std::min(n, m);
    while(large % small)
    {
        int temp = large % small;
        large = small;
        small = temp;
    }
    return {small, n*m/small};
}