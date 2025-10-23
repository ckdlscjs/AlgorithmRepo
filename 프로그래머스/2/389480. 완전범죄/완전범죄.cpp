#include <bits/stdc++.h>
using namespace std;
const int INF = 125;
int dp[42][122]; //i번째 물건까지 훔친후 B가 남긴 흔적에서 A의 최소값
int N_limit, M_limit; 
vector<vector<int>> Info;

// idx: 현재 처리할 물건 인덱스 (0부터 시작)
// b_trace: 현재까지 B 도둑이 남긴 누적 흔적
int solve(int idx, int b_trace) {
    
    // 1. 기저 조건: 모든 물건을 다 처리했을 때
    if (idx == Info.size()) {
        // 모든 물건을 훔쳤다면, A가 추가로 남길 흔적은 0이다.
        return 0; 
    }

    // 2. 메모이제이션
    int& ret = dp[idx][b_trace];
    if (ret != -1) {
        return ret;
    }

    int result = INF;
    int a_trace_current = Info[idx][0];
    int b_trace_current = Info[idx][1];

    // -----------------------------------------------------------------
    // A. 선택 1: A 도둑이 현재 물건을 훔칠 때
    // B의 흔적(b_trace)은 그대로 유지됨.
    
    // 다음 상태: idx+1, b_trace
    // next_a_trace_if_A는 '남은 물건들에서 A가 추가할 최소 흔적'
    int next_a_trace_if_A = solve(idx + 1, b_trace); 
    
    if (next_a_trace_if_A != INF) {
        // A가 훔쳤으므로, (남은 물건의 A 흔적) + (현재 물건의 A 흔적)을 더한다.
        // A의 흔적은 final_a_trace < N_limit 인지 최종 검증 시 확인된다.
        result = min(result, next_a_trace_if_A + a_trace_current);
    }
    
    // -----------------------------------------------------------------
    // B. 선택 2: B 도둑이 현재 물건을 훔칠 때
    // B의 흔적이 b_trace_current 만큼 증가함.
    
    int next_b_trace = b_trace + b_trace_current;
    
    // B 도둑의 흔적이 M_limit(n) 미만일 때만 유효 (경찰에 안 잡히는 조건)
    if (next_b_trace < M_limit) { 
        // 다음 상태: idx+1, next_b_trace
        int next_a_trace_if_B = solve(idx + 1, next_b_trace); 
        
        if (next_a_trace_if_B != INF) {
            // B가 훔쳤으므로, 현재 아이템으로 인한 A의 추가 흔적은 0이다.
            result = min(result, next_a_trace_if_B);
        }
    }
    
    return ret = result;
}
int solution(vector<vector<int>> info, int n, int m) 
{
   // 전역 변수 초기화 및 복사
    N_limit = n;
    M_limit = m;
    Info = info;
    
    // 메모이제이션 테이블 초기화 (-1: 방문하지 않음)
    // dp[40][101] 크기
    memset(dp, -1, sizeof(dp));

    // 초기 호출: 0번 물건부터, B의 흔적 0에서 시작
    // min_a_trace는 '모든 물건을 훔쳤을 때 A가 남긴 흔적의 최소 누적 개수'
    int min_a_trace = solve(0, 0);

    // 최종 결과 검증
    // 1. A의 최소 흔적이 INF가 아니고 (경로가 존재하고)
    // 2. A의 최소 흔적이 N_limit 미만이어야 함 (경찰에 안 잡히는 조건)
    if (min_a_trace >= INF || min_a_trace >= N_limit) {
        // 어떠한 방법으로도 두 도둑 모두 경찰에 붙잡히지 않게 할 수 없는 경우
        return {-1}; 
    } else {
        return {min_a_trace};
    }
}