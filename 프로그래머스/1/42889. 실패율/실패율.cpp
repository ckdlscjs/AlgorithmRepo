#include <bits/stdc++.h>

using namespace std;
const int MaxN = 505;
int stage_clear[MaxN];
int stage_amount[MaxN];

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    // stage_clear 배열과 stage_amount 배열을 0으로 초기화
    memset(stage_clear, 0, sizeof(stage_clear));
    memset(stage_amount, 0, sizeof(stage_amount));

    // 각 스테이지에 도달한 플레이어 수를 계산하고, 이전 스테이지까지의 플레이어 수를 누적하여 계산
    for (const int& num : stages) {
        for (int i = 1; i <= num; i++)
            stage_clear[i]++;
        stage_amount[num]++;
    }

    // 스테이지 번호를 담은 배열을 초기화
    for (int i = 1; i <= N; i++)
        answer.push_back(i);

    // 실패율을 기준으로 정렬
    sort(answer.begin(), answer.end(),
        [&](const int& a, const int& b) {
            double fail1 = stage_clear[a] ? (double)stage_amount[a] / (double)stage_clear[a] : 0;
            double fail2 = stage_clear[b] ? (double)stage_amount[b] / (double)stage_clear[b] : 0;
            if (abs(fail1 - fail2) < std::numeric_limits<double>::epsilon()) // 실패율이 같은 경우
                return a < b; // 스테이지 번호를 오름차순으로 정렬
            return fail1 > fail2; // 실패율을 내림차순으로 정렬
        });

    return answer;
}