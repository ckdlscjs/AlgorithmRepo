#include <bits/stdc++.h>

using namespace std;
//직원번호, 매출액
//1번은 루트, 한 직원은 최대 2개의팀, 즉 서브트리를 의미함
//모든팀은 최소 1명이상의 직원을 워크숍에 참가시켜야한다, 워크숍에 참여하는 직원의 매출액의 합이 최소가 되야한다
//sales 매출금액, links 관계도
//전체인원 2 <= N <= 300'000, 트리이므로 관계도 N-1개간선
const long long INF = 300'000*(long long)10'005;
std::vector<int> graph[300'005];
std::pair<long long, long long> DFS(const std::vector<int>& sales, int cur)
{
    if(graph[cur].size() <= 0) return {sales[cur-1], 0};
    long long sums = 0, diff = INF;
    for(const auto& iter : graph[cur])
    {
        auto ret = DFS(sales, iter);
        sums += std::min(ret.first, ret.second);
        diff = std::min(diff, ret.first - ret.second);
    }
    if(diff < 0) diff = 0;
    return {sums + sales[cur-1], sums + diff};
}
int solution(vector<int> sales, vector<vector<int>> links) 
{
    for(const auto& iter : links) graph[iter[0]].push_back(iter[1]);
    auto ret = DFS(sales, 1);
    return std::min(ret.first, ret.second);
}