#include <bits/stdc++.h>

using namespace std;
void Hanoi(std::vector<std::vector<int>>& arr, int s, int e, int t, int n)
{
    if(n <= 0) return;
    Hanoi(arr, s, t, e, n-1);
    arr.push_back({s, e});
    Hanoi(arr, t, e, s, n-1);
}
vector<vector<int>> solution(int n) 
{
    vector<vector<int>> answer;
    Hanoi(answer, 1, 3, 2, n);
    return answer;
}