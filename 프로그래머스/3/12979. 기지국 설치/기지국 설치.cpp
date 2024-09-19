#include <bits/stdc++.h>
using namespace std;
std::vector<std::pair<int, int>> waves;

int solution(int n, vector<int> stations, int w) {
    int answer = 0;
    waves.clear();  // waves 초기화

    // 각 기지국의 커버 범위를 waves에 추가
    for(int i = 0; i < stations.size(); i++) {
        waves.push_back({stations[i] - w, stations[i] + w});
    }

    w = w * 2 + 1; // 기지국 하나가 커버할 수 있는 범위
    int start = 1; // 첫 구간 시작

    for(const auto& iter : waves) {
        // 현재 기지국 범위가 시작점보다 클 때만 계산
        if (iter.first > start) {
            int amount = iter.first - start;  // 커버되지 않은 구간
            answer += (amount + w - 1) / w;   // 올림 계산하여 기지국 설치
        }
        // 시작점을 현재 기지국 범위의 끝으로 업데이트
        start = iter.second + 1;
    }

    // 마지막 기지국 이후 남은 구간 처리
    if (start <= n) {
        int amount = n - start + 1;
        answer += (amount + w - 1) / w; // 남은 구간에 대한 처리
    }

    return answer;
}
