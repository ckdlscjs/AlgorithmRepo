#include <bits/stdc++.h>

using namespace std;
int N;
bool compare(const int& a, const int& b)
{
    int diff_a = std::abs(N-a);
    int diff_b = std::abs(N-b);
    if(diff_a == diff_b)
        return a > b;
    return diff_a < diff_b;
}
vector<int> solution(vector<int> numlist, int n) 
{
    N = n;
    std::sort(numlist.begin(), numlist.end(), compare);
    return numlist;
}