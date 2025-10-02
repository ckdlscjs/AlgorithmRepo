#include <bits/stdc++.h>

using namespace std;
int solution(int n) 
{
    int cnt = std::bitset<25>(n).count();
    while(std::bitset<25>(++n).count() != cnt) {}
    return n;
}