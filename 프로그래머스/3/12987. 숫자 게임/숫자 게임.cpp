#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B) 
{
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    int idx = 0;
    int answer = 0;
    for(const auto& iter : B)
    {
        if(A[idx] < iter)
        {
            answer++;
            idx++;
        }
    }
    return answer;
}