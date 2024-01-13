#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) 
{
    int upper = numer1 * denom2 + numer2 * denom1;
    int down = denom1 * denom2;
    int A = std::max(upper, down);
    int B = std::min(upper, down);
    while(A % B != 0)
    {
        int modVal = A % B;
        A = B;
        B = modVal;
    }
    std::vector<int> answer;
    answer.push_back(upper / B);
    answer.push_back(down / B);
    return answer;
}