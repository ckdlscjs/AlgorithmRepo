#include <bits/stdc++.h>

using namespace std;
const long long MINVAL = -100'000LL * 500'000LL - 5LL;
std::vector<int> seq0, seq1;
long long Check(const std::vector<int>& arr)
{
    long long res = arr[0];
    long long curmax = arr[0];
    for(int i = 1; i < arr.size(); i++)
    {
        curmax = std::max((long long)arr[i], (long long)(curmax + arr[i]));
        res = std::max(res, curmax);
    }
    return res;
}
long long solution(vector<int> sequence) 
{
    int i = 1;
    for(const auto& iter : sequence)
    {
        seq0.push_back(iter * i);
        seq1.push_back(iter * i * -1);
        i *= - 1;
    }
    long long answer = MINVAL;
    answer = std::max(answer, Check(seq0));
    answer = std::max(answer, Check(seq1));
    return answer;
}