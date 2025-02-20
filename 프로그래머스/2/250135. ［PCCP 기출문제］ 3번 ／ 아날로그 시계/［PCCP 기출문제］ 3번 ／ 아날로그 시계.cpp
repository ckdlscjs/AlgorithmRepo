#include <bits/stdc++.h>
using namespace std;
int solution(int h1, int m1, int s1, int h2, int m2, int s2) 
{
    //to seconds
    int start = h1 * 3600 + m1*60 + s1;
    int end = h2 * 3600 + m2*60 + s2;
    //std::cout << start <<", " <<  end << '\n';
    int (*fp)(int t) = [](int t) -> int 
    {
        return t*719/43200 + t*59/3600 - (t >= 43200 ? 2 : 1);
    };
    int (*fp2)(int t) = [](int t) -> int
    {
      return ((t*59%3600 == 0 || t*719%43200 == 0) ? 1 : 0);  
    };
    return fp(end) - fp(start) + fp2(start);
}