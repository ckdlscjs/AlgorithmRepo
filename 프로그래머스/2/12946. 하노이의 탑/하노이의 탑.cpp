//https://school.programmers.co.kr/learn/courses/30/lessons/12946
#include <bits/stdc++.h>
using namespace std;
void Hanoi(std::vector<std::vector<int>>& ans, int n, int s, int d, int t)
{
    if(n <= 0)
        return;
    Hanoi(ans, n-1, s, t, d);
    ans.push_back({s, d});
    Hanoi(ans, n-1, t, d, s);
}
vector<vector<int>> solution(int n) 
{
    std::vector<std::vector<int>> answer;
    Hanoi(answer, n, 1, 3, 2);
    return answer;
}