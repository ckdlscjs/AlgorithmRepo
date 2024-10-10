//https://school.programmers.co.kr/learn/courses/30/lessons/77484
#include <bits/stdc++.h>
using namespace std;
long long int lotto = 0;
vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    for(const auto& iter : win_nums)
        lotto |= (1LL << iter);
    int cnt = 0;
    int zero_cnt = 0;
    for(const auto& iter : lottos)
    {
        cnt += (lotto & 1LL << iter) ? 1 : 0;
        zero_cnt += iter ? 0 : 1;
    }
     int max_rank = 7 - (cnt + zero_cnt);  // 최대 순위
    int min_rank = 7 - cnt;               // 최소 순위

    // 순위는 6보다 클 수 없으므로 처리
    max_rank = max_rank > 6 ? 6 : max_rank;
    min_rank = min_rank > 6 ? 6 : min_rank;

    return {max_rank, min_rank};
}